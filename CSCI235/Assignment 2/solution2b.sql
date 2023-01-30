SPOOL solution2b.lst
SET
	ECHO ON
SET
	FEEDBACK ON
SET
	LINESIZE 50
SET
	PAGESIZE 200
SET
	SERVEROUTPUT ON create
	or replace function CheapestDearestPartSupplier(partNumber number) return VARCHAR is maxValue number;

minValue number;

maxSuppkey number;

maxsName varchar(25);

maxSuppCost number;

minSuppkey number;

minsName varchar(25);

minSuppCost number;

return_list varchar(300);

begin return_list := '';

select
	max(ps_supplycost) into maxValue
from
	partsupp
where
	ps_partkey = partNumber
	and ROWNUM <= 1;

select
	min(ps_supplycost) into minValue
from
	partsupp
where
	ps_partkey = partNumber
	and ROWNUM <= 1;

select
	ps_suppkey,
	s_name,
	ps_supplycost into maxSuppkey,
	maxsName,
	maxSuppCost
from
	partsupp,
	supplier
where
	ps_suppkey = s_suppkey
	and ps_supplycost = minValue
	and rownum <= 1;

select
	ps_suppkey,
	s_name,
	ps_supplycost into minSuppkey,
	minsName,
	minSuppCost
from
	partsupp,
	supplier
where
	ps_suppkey = s_suppkey
	and ps_supplycost = maxValue
	and rownum <= 1;

return_list := 'Supplier with cheapest cost ' || minSuppkey || ', ' || minsName || ', ' || minSuppCost || '
' || 'Supplier with dearest cost ' || maxSuppkey || ', ' || maxsName || ', ' || maxSuppCost;

return return_list;

end;

/ show error
set
	serveroutput on
set
	echo on
set
	feedback on
select
	CheapestDearestPartSupplier(p_partkey)
from
	part
where
	p_partkey in ('3753', '43064', '57574', '60000');

spool off