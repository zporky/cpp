
#ifndef DVECTOR_H
#define DVECTOR_H


class DVector
{
public:
  DVector();	// constructor

  DVector(const DVector& rhs); 		  // copy constructor
  DVector& operator=(const DVector& rhs); // assignment operator

  ~DVector();	// destructor

  int     size() const;    // actual size 

  double& at(int i);	   // i-th element
  double  at(int i) const; // i-th element, const member
 
  double& operator[](int i);	    // unchecked access
  double  operator[](int i) const;  // unchecked access, const member

  void    push_back(double d);	// append to end
  void    pop_back();		// remove from end;

private:
  int     _size;	// actual number of elements
  int     _capacity;	// buffer size
  double* _ptr;		// pointer to buffer

  void copy(const DVector& rhs);   // private helper function
  void release();		   // private helper function
  void grow();			   // reallocate buffer
};


#endif /* DVECTOR_H */
