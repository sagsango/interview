// https://practice.geeksforgeeks.org/problems/game-of-xor1541/1

/* Given an array A[] of size N. The value of an array is denoted 
	 by the bit-wise XOR of all elements it contains. Find the bit-
	 wise XOR of the values of all subarrays of A[].
 */

// TODO: Use constant space
class Solution {
	public:
		int gameOfXor(int n, int A[]) {
			// code here
			int bit_arr[n], bit_xor[n], bit_cnt[n][2];
			int ans = 0;
			for(int bit=0;bit<20;++bit){
				// bit_arr = arr for cur bit
				for(int i=0;i<n;++i){
					bit_arr[i] = A[i] >> bit & 1;
				}

				// prefix xor sum
				bit_xor[0] = bit_arr[0];
				for(int i=1;i<n;++i){
					bit_xor[i] = bit_xor[i-1] ^ bit_arr[i];
				}

				// bit_cnt[i][0] = how may 0 are there after i to n-1
				bit_cnt[n-1][0] = bit_cnt[n-1][1] = 0;
				bit_cnt[n-1][bit_xor[n-1]] = 1;

				for(int j=n-2;j>=0;--j){
					for(int k=0;k<2;++k){
						bit_cnt[j][k] = bit_cnt[j+1][k];
					}
					bit_cnt[j][ bit_xor[j] ] += 1;
				}

				int cur_bit_ans = 0, prv_xor = 0;
				for(int j=0;j<n;++j){
					// prv_xor ^ some_indx_val = 1
					// some_idx_val = 1 ^ prv_xor
					cur_bit_ans ^= bit_cnt[j][ prv_xor ^ 1 ] & 1;
					prv_xor = bit_xor[j];
				}
				if( cur_bit_ans ){
					ans ^= 1ll << bit;
				}
			}
			return ans;
		}
};
