const binarySearch = (arr, target) => {
	let lo = 0,
		hi = arr.length - 1,
		mid;

	while (hi - lo > 1) {
		mid = Math.floor((lo + hi) / 2);

		if (arr[mid] < target) lo = mid + 1;
		else hi = mid;
	}

	if (arr[lo] === target) return lo;
	else if (arr[hi] === target) return hi;
	else return false;
};

const main = (arr) => {
	arr.sort((a, b) => {
		return a - b;
	});

	console.log(arr);
	const returnArr = [];
	for (let i = 0; i < arr.length; i++) {
		const number = arr[i];
		const squared = number * number;

		const index = binarySearch(arr, squared);

		if (typeof index === "number") {
			if (index !== i) returnArr.push([number, squared]);
		}
	}

	return returnArr;
};

console.log(main([16, 9, 4, 7, 8, 3, 2, 3]));
console.log(main([15, 2, 3, 6, 5, 1, 6, 7]));
