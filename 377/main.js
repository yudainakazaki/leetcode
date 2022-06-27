// class Solution {
// public:
//     var combinationSum4(vector<int>& nums, int target) {
//         map<int, unsigned int> dp;
//         dp[0] = 1;
//         for(int i = 1; i <= target; i++){
//             dp[i] = 0;
//             for(int n:nums)
//                 if(i-n >= 0)
//                     dp[i] += dp[i-n];
//         }
//         return dp[target];
//     }
// };
// int main(){
//     int target;
//     vector<int> nums;
//     int num;
//     while(true){
//         cin >> num;
//         if(num == -1) break;
//         nums.push_back(num);
//     }
//     cin >> target;
//     Solution solution;
//     cout << solution.combinationSum4(nums, target) << endl;
//     return 0;
// }
function main() {

    // const prompt = require('prompt');

    // prompt.start();

    // prompt.get(['username', 'email'], function (err, result) {
    //     if (err) {
    //         return onErr(err);
    //     }
    //     console.log('Command-line input received:');
    //     console.log('  Username: ' + result.username);
    //     console.log('  Email: ' + result.email);
    // });

    // function onErr(err) {
    //     console.log(err);
    //     return 1;
    // }

    console.log("hello");

}

if (require.main === module) {
    main();
}