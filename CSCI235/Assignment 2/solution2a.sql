SPOOL solution2a.lst
SET
	ECHO ON
SET
	FEEDBACK ON
SET
	LINESIZE 100
SET
	PAGESIZE 200
SET
	SERVEROUTPUT ON create
	or replace procedure TotalNumOfOrdersMade is previousOrder ORDERS.o_custkey % type := -1;

previousTotalPrice number := -1;

nationname char(100);

totalOrders number;

totalPrice number;

totalOrderKey number;

begin nationname := upper('&nationName');

select
	max(count(*)) into totalOrders
from
	customer
	left outer join nation on c_nationkey = n_nationkey
	left outer join orders on o_custkey = c_custkey
where
	n_nationkey = (
		select
			n_nationkey
		from
			nation
		where
			n_name = nationname
	)
group by
	o_custkey,
	c_name;

for currentRow IN (
	select
		o_custkey,
		c_name,
		o_orderkey,
		o_orderdate,
		o_totalprice
	from
		customer
		left outer join nation on c_nationkey = n_nationkey
		left outer join orders on o_custkey = c_custkey
	where
		o_custkey in (
			select
				o_custkey
			from
				customer
				left outer join nation on c_nationkey = n_nationkey
				left outer join orders on o_custkey = c_custkey
			where
				n_nationkey = (
					select
						n_nationkey
					from
						nation
					where
						n_name = nationname
				)
			having
				count(*) = totalOrders
			group by
				o_custkey
		)
	order by
		o_custkey,
		o_orderkey
) loop if previousOrder != currentRow.o_custkey then dbms_output.put_line(chr(10));

dbms_output.put_line(
	'Customer key: ' || currentRow.o_custkey || ', ' || currentRow.c_name
);

dbms_output.put_line('Total number of orders made: ' || totalOrders);

dbms_output.put_line(chr(10));

dbms_output.put_line(
	chr(6) || lpad(trim('Order key'), 12) || ' ' || lpad(trim('Order date'), 10) || ' ' || lpad(trim('Order amount'), 14)
);

end if;

--
if currentRow.o_custkey is not null then dbms_output.put_line(
	chr(9) || lpad(trim(to_char(currentRow.o_orderkey)), 12) || ', ' || lpad(
		trim(to_char(currentRow.o_orderdate, 'DD-MM-YYYY')),
		12
	) || ', ' || rpad(
		trim(
			to_char(currentRow.o_totalprice, '$999G999G999D99')
		),
		14
	)
);

end if;

select
	sum(o_totalprice) INTO totalPrice
from
	orders
where
	o_custkey = currentRow.o_custkey;

select
	max(o_orderkey) INTO totalOrderKey
from
	orders
where
	o_custkey = currentRow.o_custkey;

if currentRow.o_orderkey = totalOrderKey then dbms_output.put_line(
	chr(8) || lpad(trim('Total order amount:'), 24) || lpad(trim(to_char(totalPrice, '$999G999G999D99')), 16)
);

end if;

--
previousTotalPrice := totalPrice;

previousOrder := currentRow.o_custkey;

end loop;

dbms_output.put_line(null);

end;

/ show error exec TotalNumOfOrdersMade;

SPOOL OFF