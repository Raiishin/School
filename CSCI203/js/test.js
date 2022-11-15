const getHashAddress = (num) => {
	// return (2 * num) % 11;
	return (num % 5) + 1;
};

const nums = [65, 75, 68, 26, 59, 31, 41, 73, 114];

for (let i = 0; i < nums.length; i++) {
	console.log(nums[i], getHashAddress(nums[i]));
}
