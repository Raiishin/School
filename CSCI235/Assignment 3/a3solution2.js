print("Task 2 (i)")
db.empeProject.aggregate([{ $unwind: "$Employee" }, { $match: { "Employee.experience": "Database Design" } }, { $project: { "Employee.fName": 1, "Employee.lName": 1, _id: 0 } },]).pretty();

print("Task 2 (ii)")
db.empeProject.aggregate([{ $unwind: "$Employee" }, { $match: { "Employee.empeId": "e002" } }, { $project: { "Employee.fName": 1, "Employee.lName": 1, _id: 0 } },]).pretty();

print("Task 2 (iii)")
db.empeProject.aggregate([{ $unwind: "$Employee" }, { $match: { "Employee.experience": { $size: 4 } } }]).pretty();

print("Task 2 (iv)")
db.empeProject.update({}, { $push: { "Employee.$[elem].experience": "HIVE" } }, { arrayFilters: [{ "elem.empeId": "e001" }] });

print("Task 2 (v)")
db.empeProject.update({}, { $set: { "Employee.$[elem].email": "jamesbond$hotmail.com" } }, { arrayFilters: [{ "elem.empeId": "e001" }] });
