#ifndef VALA_BUFFER_H
#define VALA_BUFFER_H
#define BDB_FREE(instance) (instance)->close((instance), 0)
#define TRICKY_MEAN(x,y) (((x) & (y)) + (((x) ^ (y)) >> 1))
#define TRICK_FUNC() __func__
#define OBJECT_TO_BUFFER(val,type,size) (*(size) = sizeof(type), (guint8*)val)
#define OBJECT_ARRAY_TO_BUFFER(val,len,type,size) (*(size) = sizeof(type)*(len), (guint8*)val)
#define OBJECT_ARRAY_TO_ARRAY(val,len,typea,typeb,size) (*(size) = sizeof(typea)*(len)/sizeof(typeb), (void*)val)
#define OBJECT_ARRAY_FROM_BUFFER(val,len,type,size) (*(size) = (len)/sizeof(type), (void*)val)
#define BUFFER_SUB_CHUNK(val,len,idx,size) (((idx) < (len)) ? (*(size) = (len) - (idx), &(val)[(idx)]) : (*(size) = 0, NULL))

typedef gsize (*InitialisationFunction)(void*);
#define ONCE_MERGE_(a,b)  a##b
#define ONCE_LABEL_(a) ONCE_MERGE_(initval__, a)
#define ONCE_UNIQUE_NAME ONCE_LABEL_(__LINE__)
#define ONCE(res,func,data) do { static volatile gsize ONCE_UNIQUE_NAME = 0; if (g_once_init_enter (&ONCE_UNIQUE_NAME)) g_once_init_leave (&ONCE_UNIQUE_NAME, func(data)); *res = ONCE_UNIQUE_NAME; } while (0)
#define STRINGIFY(x) #x
#define VPTR(instance, ...) instance->VPTR_METHOD(instance , ## __VA_ARGS__)
#define VALA_SWAP(a, b, t) do { t _swap_temp = *(a); *(a) = *(b); *(b) = _swap_temp; } while (0)
#endif
