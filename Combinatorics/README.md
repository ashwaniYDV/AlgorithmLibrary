1) Pigeonhole Principle \
   In mathematics, the pigeonhole principle states that if m items are put into n containers, with m > n, \
   then at least one container must contain more than one item.
   
   Application of Pigeonhole Principle:
   
   Question: 
   Given an array of M integers and an integer N (N < M). \
   Prove that there always exist a pair such that their difference is divisible by N, that is (a - b) % N == 0, where a, b are any two elements of array
   
   Solution: \
   For an integer N and some integer a \
   a % N = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} = residue class
   
   Since (a - b) % N = 0 \
   From modular arithmetic we get - \
   ((a % N) - (b % N)) = 0
   a % N = b % N
   
   Let Hole = elements of residue class is total n in number \
   Pigeons = M integers of array
   
   Since M > N thus this proves the result
   
