// 1)
db.Subject.aggregate([{ $group: { _id: "$subject" } }, { $count: "Subjects" }]).pretty();

// 2)
db.Subject.aggregate([
	{
		$group: { _id: "$subject.prerequisite", "Total Subjects without prerequisistes": { $sum: 1 } },
	},
	{ $match: { _id: null } },
	{ $project: { _id: 0 } },
]).pretty();

// 3)
db.Subject.aggregate([
	{
		$group: {
			_id: "$subject.credit",
			"Total Subjects worth more than 3 credit points": { $sum: 1 },
		},
	},
	{ $match: { _id: { $gt: 3 } } },
	{ $project: { _id: 0 } },
]).pretty();

// 4)
db.Subject.aggregate([
	{ $project: { _id: 0, "subject.subTitle": 1, "subject.type": 1, "subject.credit": 1 } },
	{ $sort: { "subject.credit": -1 } },
	{ $limit: 1 },
	{ $project: { _id: 0, "subject.subTitle": 1, "subject.type": 1, "subject.credit": 1 } },
]).pretty();

// 5)
db.Subject.aggregate([
	{ $project: { _id: 0, "subject.subTitle": 1, "subject.type": 1, "subject.credit": 1 } },
	{ $sort: { "subject.subTitle": 1 } },
	{ $match: { "subject.credit": { $eq: 3 } } },
]).pretty();

// 6)
db.Subject.aggregate([{ $group: { _id: "$subject.type", count: { $sum: 1 } } }]).pretty();

// 7)
db.Subject.aggregate([
	{ $unwind: "$subject.book" },
	{
		$group: { _id: { "Book ISBN": "$subject.book.ISBN", "Book Title": "$subject.book.bookTitle" } },
	},
]).pretty();

// 8)
db.Subject.aggregate([
	{ $unwind: "$subject.book" },
	{ $match: { "subject.subCode": "CSCI235" } },
	{
		$project: {
			_id: {
				"Book Title": "$subject.book.bookTitle",
				Author: "$subject.book.author",
				"Types of Book": "$subject.book.bookType",
			},
		},
	},
]).pretty();

// 9)
db.Subject.aggregate([
	{ $unwind: "$subject.book" },
	{
		$match: {
			$or: [{ "subject.book.author": { $size: 2 } }, { "subject.book.author": { $size: 3 } }],
		},
	},
	{
		$group: {
			_id: {
				"Book ISBN": "$subject.book.ISBN",
				"Book Title": "$subject.book.bookTitle",
				"Book Publisher": "$subject.book.publisher",
			},
		},
	},
]).pretty();

// 10)
db.Subject.aggregate([
	{
		$unwind: "$subject",
	},
	{ $sort: { "subject.subCode": 1, "subject.book.publisher": -1 } },
	{
		$project: {
			_id: 0,
			"subject.subCode": 1,
			"subject.book.bookTitle": 1,
			"subject.book.publisher": 1,
		},
	},
]).pretty();
