// Find smallest number x such that fun(x) = k wher f(n) is of following monotic shape (non decreasing function)
/*



                                                                                #
                                                                              #
                                                                           #
                                                                        #
                                                                   #
                                                            #
                                                    #
                                          #
                                 #        ^
                        #                 |
               #                          |
       #                                  |
  #                                       |
                                          |
                                 This is the optimam point
                          
                          
In this case ham right to optimum move krenge na i left to optimum
If f(n) would have been just mirror image of this about y-axix (non increasing function) then ham left to optimum point move krte 
*/



// (non decreasing function)
while(l <= r) {
    int mid = (l+r)/2;
    x = fun(mid);
    
    // right side ki taraf se left ki taraf move kro 
    if(x >= k) {
        r = mid - 1;
        res = mid;
    } else {
        l = mid + 1;
    }
}








// Agressive cows (non increasing function)
int low = 0, high = a[n - 1], mid, best = 0;
while (low <= high) {
    mid = (low + high) / 2;
    int cnt = 1, left = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[left] >= mid)
            left = i, cnt++;
    }
    if (cnt >= c) {
        best = mid;
        low = mid + 1;
    } else {
        high = mid - 1;
    }
}
