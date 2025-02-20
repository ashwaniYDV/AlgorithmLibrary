# Resources
* [Striver - Requirements needed to construct a Unique Binary Tree](https://youtu.be/9GMECGQgWrQ?si=yVcsNZrJTBEK2Oim)


# Theory

### Q) Can you construct a unique binary tree with the following?

| 🔧 **Given Traversals**       | ✅ **Unique Binary Tree Possible?** | 📝 **Reason** |
|:-----------------------------:|:---------------------------------:|:--------------------------------------------:|
| 🟦 Preorder and Postorder     | ❌ No                            | Multiple trees can have the same preorder and postorder but different structures. |
| 🟦 Inorder and Preorder      | ✅ Yes                           | Inorder provides relative positions, and preorder helps determine the root at each step. |
| 🟦 Inorder and Postorder     | ✅ Yes                           | Inorder gives node positions, and postorder helps identify roots uniquely. |


    Note:-
    * For a given (Preorder + Postorder) taversals pair, we can generate multiple possible binary trees.
    * Inorder traversal is required along with either preorder / postorder to construct unique binary tree.


### Q) How does inorder + preorder/postorder construct unique binary tree?
    Imagine that you have the following pre-order traversal: a,b,c,d,e,f,g. What does that tell you?
    
    You know that a is the root of the tree, this follows from the definition of a pre-order traversal. So far so good.
    
    You also know that the rest of your list is the traversal of the left subtree followed by the traversal of the right subtree. Unfortunately you don't know where the split is. It could be that all of them belong to the left tree, it could be that all of them belong to the right tree, or b,c go left and d,e,f,g go right and so on.
    
    How to resolve the ambiguity? Well, let's take a look at the in-order traversal, what is its defining property? Any elements in the left subtree of a will come before a in the in-order traversal and any elements in the right subtree will come after a. Again, this follows from the definition of in-order traversal.
    
    So what we need to do is take a look at the in-order traversal (let's say it's c,b,a,d,e,f,g). We can see that b and c come before a, therefore they're in the left subtree, while d,e,f and g are in the right subtree. In other words, as position in the in-order traversal uniquely determines which nodes will be in its left/right subtrees.
    
    And this is great because we can now go on and solve the two subtrees recursively: pre-order b,c/in-order c,b and pre-order d,e,f,g/in-order d,e,f,g.
    
    And you can continue this recursively until all subtrees only contain a single element, where the solution is trivially unique.
    
    And since at each step we could prove that there is only one valid way to continue, the result is that a given pair of in-order and pre-order traversals can only belong to a single tree.