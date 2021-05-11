// Find smallest number x such that fun(x) = k wher f(n) is of following monotic shape
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
If f(n) would have been just mirror image of this about y-axix then ham left to optimum point move krte 
*/

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
