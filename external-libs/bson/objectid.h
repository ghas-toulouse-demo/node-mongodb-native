#ifndef OBJECTID_H_
#define OBJECTID_H_

#include <node.h>
#include <node_object_wrap.h>
#include <v8.h>

using namespace v8;
using namespace node;

class ObjectID : public ObjectWrap {  
  public:
    char *oid;
    
    ObjectID(char *oid);
    ~ObjectID();    

    // Functions available from V8
    static void Initialize(Handle<Object> target);    
    static Handle<Value> ToString(const Arguments &args);
    static Handle<Value> Inspect(const Arguments &args);
    static Handle<Value> ToHexString(const Arguments &args);

    // Constructor used for creating new Long objects from C++
    static Persistent<FunctionTemplate> constructor_template;
    
  private:
    static Handle<Value> New(const Arguments &args);
    
    // Generates oid's (Based on BSON C lib)
    static char *oid_id_generator();
    static char *uint32_to_char(uint32_t value);
};

#endif  // OBJECTID_H_