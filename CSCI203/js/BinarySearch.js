const binarySearch = (arr, target) => {
	let lo = 0,
		hi = arr.length - 1,
		mid;

	while (hi - lo > 1) {
		mid = Math.floor((lo + hi) / 2);
		if (arr[mid] < target) lo = mid + 1;
		else hi = mid;
	}

	if (arr[lo] === target) return `Found at Index ${lo}`;
	else if (arr[hi] === target) return `Found at Index ${hi}`;
	else return `Not Found`;
};

const arr = [1, 2, 4, 6, 7, 10];

console.log(binarySearch(arr, 6));
