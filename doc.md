try - defines the code to test
throw - triggers an exception
catch - handles the error

try {
  // Code that may throw an exception
  throw 505;
}
catch (int errorCode) {
  cout << "Error occurred: " << errorCode;
}

## Exception example

``` cpp
class MyException : public std::exception {
    private:
        std::string _message;
    public:
        explicit MyException(const std::string &message) : _message(message) {}
        const char* what() const noexcept override {
            return _message.c_str();
        }
} ;
```

``` cpp
#include <exception>  // Provides std::exception
#include <string>     // Provides std::string

// Custom exception class that inherits from std::exception
class MyException : public std::exception {
private:
    // We store the error message as a std::string.
    // This means the object OWNS its message.
    // Memory is managed safely and automatically.
    std::string _message;

public:
    // 'explicit' prevents implicit conversions like:
    // throw "error";  (which could otherwise implicitly construct MyException)
    explicit MyException(const std::string& message)
        // Member initializer list:
        // The member _message is directly constructed
        // using the constructor parameter 'message'.
        //
        // IMPORTANT:
        // - Left side  -> class member
        // - Right side -> constructor parameter
        //
        // This is more efficient than assigning inside the constructor body,
        // because the std::string is constructed only once.
        : _message(message)
    {
        // Constructor body is empty because initialization
        // was already done in the initializer list.
    }

    // Override of std::exception::what()
    //
    // Signature must EXACTLY match the base class:
    //   virtual const char* what() const noexcept;
    //
    // - const      -> this function does not modify the object
    // - noexcept   -> guarantees that this function will NOT throw
    // - override   -> ensures we are correctly overriding a virtual method
    //
    // If the signature does not match exactly, the compiler will error.
    const char* what() const noexcept override {
        // std::string::c_str() returns a pointer to the internal
        // null-terminated character array.
        //
        // This pointer remains valid as long as the std::string
        // object (_message) exists and is not modified.
        //
        // Since _message is a member of this object,
        // and this object is alive while the exception exists,
        // returning c_str() here is safe.
        return _message.c_str();
    }
};
```
