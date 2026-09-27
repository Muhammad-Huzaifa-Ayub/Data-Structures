#include "Stack.h"

int main()
{
     Stack<int> s(3);

     cout << "Capacity: " << s.GetCapacity() << endl;
     cout << "Size: " << s.size() << endl;
     cout << "Is Empty: " << boolalpha << s.isEmpty() << endl;

     s.push(10);
     s.push(20);
     s.push(30);

     cout << "\nStack: ";
     s.display();

     cout << "Size: " << s.size() << endl;
     cout << "Is Full: " << s.isFull() << endl;

     cout << "\nCapacity before resize: " << s.GetCapacity() << endl;

     s.push(40);

     cout << "Stack after pushing 40: ";
     s.display();

     cout << "Capacity after resize: " << s.GetCapacity() << endl;

     cout << "Size: " << s.size() << endl;

     cout << "\nTop element: " << s.peek() << endl;

     cout << "Contains 20: " << s.contains(20) << endl;

     cout << "Contains 100: " << s.contains(100) << endl;

     cout << "\nPopped: " << s.pop() << endl;

     cout << "Stack after pop: ";
     s.display();

     Stack s2(s);

     cout << "\nOriginal stack: ";
     s.display();

     cout << "Copied stack: ";
     s2.display();

     s2.pop();

     cout << "Original after modifying copy: ";
     s.display();

     cout << "Copied stack: ";
     s2.display();

     Stack<int> s3(2);

     s3.push(100);
     s3.push(200);

     cout << "\ns3 before assignment: ";
     s3.display();

     s3 = s;

     cout << "s3 after assignment: ";
     s3.display();

     s3.push(500);

     cout << "Original s: ";
     s.display();

     cout << "s3 after adding 500: ";
     s3.display();

     s3 = s3;

     cout << "\ns3 after self-assignment: ";
     s3.display();

     Stack<int> s4(5);

     s4.push(1);
     s4.push(2);
     s4.push(3);
     s4.push(4);
     s4.push(5);

     cout << "\nBefore reverse: ";
     s4.display();

     s4.reverse();

     cout << "After reverse: ";
     s4.display();

     cout << "Size: " << s4.size() << endl;
     cout << "Capacity: " << s4.GetCapacity() << endl;

     s4.clear();

     cout << "\nAfter clear: ";
     s4.display();

     cout << "Size: " << s4.size() << endl;
     cout << "Is Empty: " << s4.isEmpty() << endl;
     cout << "Capacity: " << s4.GetCapacity() << endl;

     s4.push(50);
     s4.push(60);

     cout << "\nAfter reusing stack: ";
     s4.display();

     Stack<int> s5(5);

     s5.push(10);
     s5.push(20);
     s5.push(30);
     s5.push(40);

     cout << "\nLIFO test:\n";

     while (!s5.isEmpty())
     {
          cout << s5.pop() << endl;
     }

     cout << "Is Empty: " << s5.isEmpty() << endl;

     cout << "\nAll tests completed." << endl;

     return 0;
}