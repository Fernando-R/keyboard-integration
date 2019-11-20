#include <node.h>
#include <iostream>
#include <windows.h>
#include <string.h>
#include <sstream>


using namespace v8;
using namespace std;

void KeyDown(const FunctionCallbackInfo<Value>& args) {
    v8::Isolate* isolate = args.GetIsolate(); 
    v8::String::Utf8Value str(isolate, args[0]);
    std::string cppStr(*str);
    
    INPUT input;

    int key; 

    std::stringstream stri;
    stri << cppStr;
    stri >> std::hex >>     key;
    
    memset(&input,0,sizeof(input));
    input.type=INPUT_KEYBOARD;
    
    input.ki.wVk= key;
    SendInput(1,&input,sizeof(INPUT));
}

void KeyUp(const FunctionCallbackInfo<Value>& args) {
    v8::Isolate* isolate = args.GetIsolate(); 
    v8::String::Utf8Value str(isolate, args[0]);
    std::string cppStr(*str);
       
    INPUT input;
    
    int key; 

    std::stringstream stri;
    
    memset(&input,0,sizeof(input));
    input.type=INPUT_KEYBOARD;
    
    input.ki.wVk= key;

    input.ki.dwFlags=KEYEVENTF_KEYUP;
    SendInput(1,&input,sizeof(INPUT));
}

void Initialize(Local<Object> exports) {
   NODE_SET_METHOD(exports, "KeyUp", KeyUp);
   NODE_SET_METHOD(exports, "KeyDown", KeyDown);
}

NODE_MODULE(addon, Initialize);