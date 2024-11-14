#include <iostream>
#include <chrono>
#include <memory>

struct node   /* one node of the search tree */
{
  node(int val) : value_(val) { } // constructor for make_unique 	
  int                   value_;   // payload
  std::unique_ptr<node> left_;    // pointer to left child  
  std::unique_ptr<node> right_;   // pointer to right child 
};

void insert(std::unique_ptr<node> &root, int i);
void print(const std::unique_ptr<node> &root);
//void clear(node *root);

int main()
{
  std::unique_ptr<node> head;	/* pointer to binary search tree */
  int i;
  int cnt = 0;

  auto start = std::chrono::system_clock::now();  // start timer
  while ( std::cin >> i )
  {
    ++cnt;
    insert(head, i);	  /* recursive insert */
  }  
  auto end = std::chrono::system_clock::now();  // stop timer

  print(head);  /* print tree elements: recursive inorder */
  const std::chrono::duration<double> elapsed = end - start;					
  std::cerr << "\nsorted " << cnt << " elements, ";
  std::cerr << "elapsed time = " << elapsed.count() << "s\n";
  //std::cerr << "elapsed time = " << elapsed         << "s\n"; // C++20

  // clear(head); // delete the tree: recursive postorder 
  return 0;
}

void insert(std::unique_ptr<node>  &root, int i)
{
  if ( nullptr == root )  /* need to allocate new element */
  {
    root = std::make_unique<node>(i);
  }	  
  else /* not to allocate, just descent left or right */
  {
    if ( i < root->value_ )
      insert( root->left_, i);  /* descend to left */
    else
      insert( root->right_, i);	/* descend to right */
  }
}
void print(const std::unique_ptr<node> &root)
{
  if ( root ) 	/* if this is a real node */
  {	  
    print(root->left_);
    std::cout << root->value_ << " ";
    print(root->right_);  
  }
}	
/*
void clear(node *root)
{
  if ( root ) 	// if this is a real node 
  {	  
    clear(root->left_);
    clear(root->right_);  
    delete root;          // postorder 
  }
}
*/

