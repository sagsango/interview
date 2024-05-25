// https://practice.geeksforgeeks.org/problems/maximum-tip-calculator2631/1/?company[]=Amazon&company[]=Amazon&page=28&query=company[]Amazonpage28company[]Amazon
/*
	 Rahul and Ankit are the only two waiters in the Royal Restaurant. 
	 Today, the restaurant received n orders. The amount of tips may 
	 differ when handled by different waiters, if Rahul takes the ith 
	 order, he would be tipped ai rupees and if Ankit takes this order,
	 the tip would be bi rupees.
	 In order to maximize the total tip value they decided to distribute
	 the order among themselves. One order will be handled by one person
	 only. Also, due to time constraints Rahul cannot take more than x 
	 orders and Ankit cannot take more than y orders. It is guaranteed 
	 that x + y is greater than or equal to n, which means that all the
	 orders can be handled by either Rahul or Ankit. Find out the maximum 
	 possible amount of total tip money after processing all the orders.
 */


class Solution{
  public:
    long long maxTip(int a[], int b[], int n, int x, int y) {
        // code here

        // a[i] > a[j]
        // b[i] < b[j]

        // a[j] < a[i]

        // b[i] < b[j]

        // b[i] + a[j] < a[i] + b[j]

        // a[i] + b[j] > b[i] + a[j]

        vector<int>arr(n);
        for(int i=0;i<n;++i){
            arr[i] = i;
        }

        auto cmp = [&](const int &i, const int &j ){
            return a[i] + b[j] > b[i] + a[j];
        };

        sort(arr.begin(),arr.end(),cmp);

        int idx = 0, asum = 0, bsum = 0, sum = 0;
        while( idx < n  && idx < x ){
            asum += a[arr[idx]];
            ++idx;
        }

        sum = asum;

        for(int i=n-1;i >= 0 && i >= n - y; --i){
            while( idx > i ){
                asum -= a[arr[--idx]];
            }
            bsum += b[arr[i]];

            sum = max(sum, asum + bsum );
        }
        return sum;
    }
};
