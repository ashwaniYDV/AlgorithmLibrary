/*

// Find smallest number num such that fun(num) = k

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
*/
