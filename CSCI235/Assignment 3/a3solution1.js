db.jygt002.insert([
	{
		CUSTOMER: [
			{ custID: "c001", fName: "gavin", lName: "tan", accounts: { acctNumber: ["a001", "a002"] } },
		],
		ACCOUNT: [
			{
				accountNumber: "a001",
				balance: 1000,
				custID: "c001",
				brchName: "b001",
			},
			{
				accountNumber: "a002",
				balance: 2000,
				custID: "c001",
				brchName: "b001",
			},
		],
		BRANCH: [
			{
				brchName: "b001",
				address: { street: "100 branch road", city: "Singapore", Country: "Singapore" },
				employees: { eNum: ["e001", "e002"] },
			},
		],
		EMPLOYEE: [
			{ eNum: "e001", fullName: "Mlon Eusk" },
			{ eNum: "e002", fullName: "Parry Hotter" },
		],
	},
]);
