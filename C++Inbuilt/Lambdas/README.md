### Resources
* https://aryanc403.com/blog/y_combinator/

```
𝐋𝐚𝐦𝐛𝐝𝐚 𝐅𝐮𝐧𝐜𝐭𝐢𝐨𝐧𝐬 101

Are you tired of defining numerous parameters in your functions?

In competitive programming, speed is crucial. 
When problems involving recursion, such as DFS or dynamic programming, arise, we often need to pass vectors or other data to functions. 
This can get tedious.

Let’s dive into lambda functions. 
Without overwhelming you with theory, here’s what you need to implement one.

Key Components to Create a Lambda Function:
1. 𝐕𝐚𝐫𝐢𝐚𝐛𝐥𝐞 𝐍𝐚𝐦𝐞: This will store the lambda function.
2. 𝐏𝐚𝐫𝐚𝐦𝐞𝐭𝐞𝐫𝐬: Just like a regular recursive function.
3. 𝐑𝐞𝐟𝐞𝐫𝐞𝐧𝐜𝐞 𝐭𝐨 𝐭𝐡𝐞 𝐅𝐮𝐧𝐜𝐭𝐢𝐨𝐧: Used to make recursive calls.
4. 𝐑𝐞𝐭𝐮𝐫𝐧 𝐓𝐲𝐩𝐞: Necessary if you want recursive calls.

The only difference is that, inside your lambda, instead of calling the function by its name, you use the variable name, passing it again as a reference. 
This allows recursion to occur within the lambda function itself.

𝐈𝐦𝐩𝐨𝐫𝐭𝐚𝐧𝐭: 
Variable-sized arrays can’t be used inside lambda functions. 
So, instead of defining vector<int> adj[n], 
you’ll need to define your adjacency list as vector<vector<int>> adj(n).

As you can see, this structure eliminates the need to pass the adjacency list or the visited vector every time. 
Instead, they are available within the lambda’s scope, simplifying the recursive logic.
```