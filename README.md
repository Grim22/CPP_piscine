<h2>Piscine C++</h2>
<p>Module 00: Namespace, class, member functions, stdio stream, initialization lists, static, const, and lots of basic stuff</p>
<p>Module 01: Memory allocation, References, Pointers to members, File streams</p>
<p>Module 02: Ad-hoc polymorphism, operators overload and canonical classes</p>
<p>Module 03: Inheritance</p>
<p>Module 04: Subtype polymorphism, abstract classes, interfaces</p>
<p>Module 05: Exceptions</p>
<p>Module 06: C++ casts</p>
<p>Module 07: C++ templates</p>
<p>Module 08: Templated containers, iterators, algorithms</p>
<p>&nbsp;</p>
<h2>Ressources</h2>
<p>&nbsp;</p>
<p>General:</p>
<p>"man" of c++: cplusplus.com</p>
<p>&nbsp;</p>
<p><strong>Module 00</strong>:</p>
<p>&nbsp; &nbsp; - reading input with cin.ignore() and getline: <a href="https://stackoverflow.com/questions/25475384/when-and-why-do-i-need-to-use-cin-ignore-in-c">stackoverflow</a></p>
<p>&nbsp; &nbsp; - initalizing const member: member initializer list: <a href="https://www.learncpp.com/cpp-tutorial/8-5a-constructor-member-initializer-lists/">learncpp</a></p>
<p>&nbsp; &nbsp; - rvalues and lvalues <a href="https://www.internalpointers.com/post/understanding-meaning-lvalues-and-rvalues-c">internalpointers.com</a></p>
<p><strong>Module 01:</strong>&nbsp;</p>
<p>&nbsp; &nbsp; - pointers vs references: <a href="https://www.geeksforgeeks.org/pointers-vs-references-cpp/">geeksforgeeks</a></p>
<p>&nbsp; &nbsp; - returning reference to local variable: <a href="https://stackoverflow.com/questions/4643713/c-returning-reference-to-local-variable">stackoverflow</a></p>
<p>&nbsp; &nbsp; - temporary objects: <a href="http://www.gotw.ca/gotw/002.htm">gotw</a></p>
<p><strong>Module 02:&nbsp;</strong></p>
<p>&nbsp; &nbsp; - overloading the subscript ([]) operator: <a href="https://www.learncpp.com/cpp-tutorial/98-overloading-the-subscript-operator/">learncpp</a></p>
<p><strong>Module 03</strong>:&nbsp;</p>
<p>&nbsp; &nbsp; - overriding behaviour of base class member function: <a href="https://www.learncpp.com/cpp-tutorial/11-6a-calling-inherited-functions-and-overriding-behavior/">learncpp</a></p>
<p>&nbsp; &nbsp; - virtual base class: <a href="https://www.geeksforgeeks.org/virtual-base-class-in-c/">geeksforgeeks</a></p>
<p><strong>Module 04:</strong>&nbsp;</p>
<p>&nbsp; &nbsp; - why virtual destructors <a href="https://stackoverflow.com/questions/461203/when-to-use-virtual-destructors">stackoverflow</a> and&nbsp; <a href="https://stackoverflow.com/questions/3628529/should-c-interfaces-have-a-virtual-destructor">stackoverflow</a></p>
<p>&nbsp; &nbsp; - why operators dont need to be virtual <a href="https://stackoverflow.com/questions/669818/virtual-assignment-operator-c">stackoverflow</a></p>
<p>&nbsp; &nbsp; - polymorphic clones: <a href="https://www.fluentcpp.com/2017/09/08/make-polymorphic-copy-modern-cpp/&nbsp;">fluentcpp</a></p>
<p>&nbsp; &nbsp; - pure virtual functions WITH implementation <a href="https://stackoverflow.com/questions/2089083/pure-virtual-function-with-implementation">stackoverflow</a></p>
<p><strong>Module 07</strong>:</p>
<p>&nbsp; &nbsp; - where to implement template ? (.hpp ? .cpp ? .ipp ?) <a href="https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file">stackoverflow</a></p>
<p><strong>Module 08:</strong></p>
<p>&nbsp; &nbsp; - how std::deque work internally: <a href="https://thispointer.com/what-is-stddeque-and-how-deque-works-internally">thispointer</a></p>
<p>&nbsp;</p>
<p>&nbsp;</p>
<h2>Notes</h2>
<p>&nbsp;</p>
<p>Static and dynamic binding // virtual keyword</p>
<p>&nbsp; &nbsp; ex:</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; Pointer to base class Base *p = q</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; -&gt; has a declared type p&nbsp;</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; -&gt; has a "real type" q, that can be either base or derived class (pointer to a derived class is "type compatible" with a pointer to base class)</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; Call to member function p-&gt;func() that both Base and derived classes share.</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; Which func() to call ? Base::func() or Derived::func() ?</p>
<p>&nbsp; &nbsp; "Linkage", "Binding": link between a function call and a function definition ("the program binds to the adress where the function is defined")</p>
<p>&nbsp; &nbsp; Static (early) linkage: done at compilation time -&gt; p is of declared type, Base::func() will be linked</p>
<p>&nbsp; &nbsp; Dynamic (late) linkage: done at execution time -&gt; p is of real type, Derived::func() will be linked</p>
<p>&nbsp; &nbsp; When "virtual" is added before a function declaration, dynamic linkage is done</p>
<p>&nbsp;</p>
<p>Polymorphism</p>
<p>&nbsp; &nbsp; (Run-time) polymorphism: virtual functions</p>
<p>&nbsp; &nbsp; &lt;&gt; (Compile-time)polymorphism: function overloading</p>
<p>&nbsp;</p>
<p>Abstract classes and interfaces</p>
<p>&nbsp; &nbsp; Abstract class: at least one function has no definition: virtual func () = 0 ("pure virtual function)</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; - cannot be instanciated: can only be used as base class (func() will be defined in derived classes)</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; - can have attributes (so must also have a constructor, which will be called when instanciating derived class objects)</p>
<p>&nbsp; &nbsp; Interface: &nbsp;member functions are only pure virtual functions</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; - can't have any attributes (no need for constructor)</p>
<p>&nbsp;</p>
<p>Exceptions:</p>
<p>&nbsp; &nbsp; A try catch block is placed aroud the calls that might throw an exception</p>
<p>&nbsp; &nbsp; A try block is followed by one or more catch blocks: each catch block can catch a different type of Exceptions</p>
<p>&nbsp; &nbsp; After an exception is thrown, the execution resumes after the try catch block (not after the Throw statement)</p>
<p>&nbsp;</p>
<p>Casts:</p>
<p>&nbsp; &nbsp; Different cast natures:</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; - classic "conversion" (ex: from int to float): underlying values (bits) are change&nbsp;</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; - identitary conversion: values are not changed, only the way there are interpreted (concerns only poiters)</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; - type qualifier conversion: const &lt;-&gt; non const</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; - (specific to CPP) upcast (derived-&gt;base) and downcast (base-&gt;derived).&nbsp;</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Ex: Base *p = &amp;q, where q is of type derived</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Rq: concerns pointers&nbsp;</p>
<p>&nbsp; &nbsp; Two ways to cast in C:</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; - implicit cast (done for example when an integer is "promoted" to double)</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; - explicit cast: var = (type) var1</p>
<p>&nbsp; &nbsp; In CPP, 5 ways to cast: implicit cast, static_cast, dynamic_cast, reinterpret_cast, const_cast</p>
<p>&nbsp; &nbsp; Implicit cast is allowed in the following cases:</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; - conversion from "smaller" type to "larger" type (int to float)</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; - upcast</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; - identitary conversion to void* (void* v = p)</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; - non const to const (const int c_i = i)</p>
<p>&nbsp; &nbsp; Downcast: Static_cast or dynamic_cast ?</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; Downcast (base class pointer BC to derived class pointer DC) can be problematic: if BC "real" type is the same as DC, no problem. Else, if it is of parent class, or other derived class, it will not be compatible with DC</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; -&gt; static_cast is done at compile time: it will not resolve BC "real" type: if there is a problem, programm will crash</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; -&gt; dynamic_cast is done at run-time: it will resolve BC "real" type and linkage will fail if there is an incompatibility</p>
<p>&nbsp; &nbsp; Cast operators:</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; Cast operators are member functions of a class, that define a default behaviour when object is converted to another type ("user defined conversion function")</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; ex: foo a; int b; b = a -&gt; member function operator int() will handle it</p>
<p>&nbsp;</p>
<p>Const class objects</p>
<p>&nbsp; &nbsp; - can't modify attributes</p>
<p>&nbsp; &nbsp; - so can only call member functions declared as const</p>
<p>&nbsp; &nbsp; - a class can have two overloads of member function func(), one const and the other non const. A const object will automatically call the func() const function&nbsp;</p>
<p>&nbsp; &nbsp; cf: <a href="https://www.learncpp.com/cpp-tutorial/810-const-class-objects-and-member-functions/">learncpp</a></p>
