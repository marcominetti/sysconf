/* Based on the sysconf node module by Jen Andre, ported to node >= 0.11
 * and some additons by Alexander Vassilev
 *
 * This code is PUBLIC DOMAIN, and is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND. See the accompanying 
 * LICENSE file.
 */

#include <v8.h>
#include <node.h>
#include <nan.h>
#include <sys/types.h>
#include <unistd.h>
#include <map>

#define MY_THROW_EXCEP(msg) do {   \
    NanThrowError(msg);         \
    NanReturnUndefined();       \
} while(0)

using namespace v8;
typedef std::map<std::string, int> NameIdMap;

NAN_METHOD(call)
{
  NanEscapableScope();
  if (args.Length() != 1)
      MY_THROW_EXCEP("Function expects one integer or string argument");

  int id = -1;
  v8::Value* arg0 = *args[0];

  if (!arg0->IsInt32())
      MY_THROW_EXCEP("Parameter must be integer");

  id = arg0->Int32Value();
  if (id < 0)
      MY_THROW_EXCEP("Parameter must be a non-negative integer");
  long result = sysconf(id);
  if (result > 0)
      NanReturnValue(NanNew<Number>(result));
   else
      MY_THROW_EXCEP("sysconf parameter id not recognized by operating system");
}

#define ADD_KEY(name)            \
    obj->Set(NanNew<String>(#name), NanNew<Number>((int)name))

NAN_METHOD(keys)
{
  NanEscapableScope();
  Local<Object> obj = NanNew<Object>();

#ifdef _SC_ARG_MAX
  ADD_KEY(_SC_ARG_MAX);
#endif

#ifdef _SC_CHILD_MAX
  ADD_KEY(_SC_CHILD_MAX);
#endif

#ifdef _SC_HOST_NAME_MAX
  ADD_KEY(_SC_HOST_NAME_MAX);
#endif

#ifdef _SC_LOGIN_NAME_MAX
  ADD_KEY(_SC_LOGIN_NAME_MAX);
#endif

#ifdef _SC_OPEN_MAX
  ADD_KEY(_SC_OPEN_MAX);
#endif

#ifdef _SC_PAGESIZE
  ADD_KEY(_SC_PAGESIZE);
#endif

#ifdef _SC_RE_DUP_MAX
  ADD_KEY(_SC_RE_DUP_MAX);
#endif

#ifdef _SC_STREAM_MAX
  ADD_KEY(_SC_STREAM_MAX);
#endif

#ifdef _SC_SYMLOOP_MAX
  ADD_KEY(_SC_SYMLOOP_MAX);
#endif

#ifdef _SC_TTY_NAME_MAX
  ADD_KEY(_SC_TTY_NAME_MAX);
#endif

#ifdef _SC_TZNAME_MAX
  ADD_KEY(_SC_TZNAME_MAX);
#endif

#ifdef _SC_VERSION
  ADD_KEY(_SC_VERSION);
#endif

#ifdef _SC_CLK_TCK
  ADD_KEY(_SC_CLK_TCK);
#endif

#ifdef _SC_NPROCESSORS_ONLN
  ADD_KEY(_SC_NPROCESSORS_ONLN);
#endif

#ifdef _SC_PAGE_SIZE
  ADD_KEY(_SC_PAGE_SIZE);
#endif

#ifdef _SC_PHYS_PAGES
  ADD_KEY(_SC_PHYS_PAGES);
#endif

#ifdef _SC_AVPHYS_PAGES
  ADD_KEY(_SC_AVPHYS_PAGES);
#endif
  NanReturnValue(obj);
}


void init(Handle<Object> target)
{
  target->Set(NanNew<String>("sysconf"), NanNew<FunctionTemplate>(call)->GetFunction());
  target->Set(NanNew<String>("keys"), NanNew<FunctionTemplate>(keys)->GetFunction());
}

NODE_MODULE(sysconfx, init);
