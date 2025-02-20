/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let result = [];
    
    nums.forEach((num, i) => {
        nums.forEach((num2, j) => {
            if (i !== j && num + num2 === target) {
                result = [i, j];
            }
        });
    });

    return result;
};
