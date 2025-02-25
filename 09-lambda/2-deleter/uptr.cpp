#include <iostream>
#include <chrono>
#include <memory>

struct node;
using node_ptr = std::unique_ptr<node,void(*)(node*)>;

struct node   /* one node of the search tree */
{
  node(int val,void(*d)(node*)) : // constructor for make_unique 	
	           value_(val), left_(nullptr,d), right_(nullptr,d) {}
  int      value_;  // payload
  node_ptr left_;   // to left child  
  node_ptr right_;  // to right child 
};

auto del = [](node *p) { std::cerr << "deleting node " << p->value_ << '\n';
	                 delete p; 
                       };

void insert(node_ptr &root, int i);
void print(const node_ptr &root);
void draw(const node_ptr &root, int level = 10);

int main()
{
  node_ptr head{nullptr,del};  /* pointer to binary search tree */
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
  std::cout << '\n';

  const std::chrono::duration<double> elapsed = end - start;					
  std::cerr << "\nsorted " << cnt << " elements, ";
  std::cerr << "elapsed time = " << elapsed.count() << "s\n";
  //std::cerr << "elapsed time = " << elapsed         << "s\n"; // C++20

  // clear(head); // delete the tree: recursive postorder 
  return 0;
}

void insert(node_ptr  &root, int i)
{
  if ( nullptr == root )  /* need to allocate new element */
  {
    root.reset(new node{i,del});
  }	  
  else /* not to allocate, just descent left or right */
  {
    if ( i < root->value_ )
      insert( root->left_, i);  /* descend to left */
    else
      insert( root->right_, i);	/* descend to right */
  }
}
void print(const node_ptr &root)
{
  if ( root ) 	/* if this is a real node */
  {	  
    print(root->left_);
    std::cout << root->value_ << " ";
    print(root->right_);  
  }
}

