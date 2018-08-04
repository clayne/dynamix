// DynaMix
// Copyright (c) 2013-2018 Borislav Stanimirov, Zahary Karadjov
//
// Distributed under the MIT Software License
// See accompanying file LICENSE.txt or copy at
// https://opensource.org/licenses/MIT
//
// this file is automatically generated by a script
//


#define I_DYNAMIX_MESSAGE0_DECL(export, message_name, method_name, return_type, constness, message_mechanism ) \
    /* mechanism shows whether it's a multicast or unicast */ \
    \
    /* step 1: define the message struct */ \
    struct export I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name) : public ::dynamix::internal::I_DYNAMIX_MESSAGE_CALLER_STRUCT(message_mechanism) \
        <I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name), constness ::dynamix::object, return_type > \
    { \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)() \
            : I_DYNAMIX_MESSAGE_CALLER_STRUCT(message_mechanism)(I_DYNAMIX_PP_STRINGIZE(message_name)) \
        {} \
        /* MethodOwner is the actual owner of the message (either the mixin or one of its parents) */ \
        template <typename Mixin, typename MethodOwner> \
        ::dynamix::internal::func_ptr get_caller_for() const \
        { \
            /* prevent the linker from optimizing away the caller function */ \
            static caller_func the_caller = I_DYNAMIX_CALLER_NAME(constness)<Mixin, MethodOwner, &MethodOwner::method_name>; \
            /* cast the caller to a void (*)() - safe according to the standard */ \
            return reinterpret_cast< ::dynamix::internal::func_ptr>(the_caller); \
        } \
    }; \
    /* step 2: define a message tag, that will be used to identify the message in feature lists */ \
    /* it would have been nice if we could set this global variable to the unique global instance of the feature*/ \
    /* but unfortunately we cannot trust dynamic libraries to keep it straight for us */ \
    /* hence we rely on a getter like the mixin one */ \
    extern export I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name) * I_DYNAMIX_MESSAGE_TAG(message_name); \
    /* step 3: declare the feature getter and manual registrator for the message */ \
    extern export ::dynamix::feature& _dynamix_get_mixin_feature_safe(const I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)*); \
    extern export const ::dynamix::feature& _dynamix_get_mixin_feature_fast(const I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)*); \
    extern export void _dynamix_register_mixin_feature(const I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)*); \

#define I_DYNAMIX_MESSAGE0_UNI(export, message_name, method_name, return_type, constness ) \
    I_DYNAMIX_MESSAGE0_DECL(export, message_name, method_name, return_type, constness, unicast ) \
    /* step 4: define the message function -> the one that will be called for the objects */ \
    inline return_type method_name(constness ::dynamix::object& _d_obj ) \
    {\
        return I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(_d_obj ); \
    }\
    /* also define a pointer function */ \
    inline return_type method_name(constness ::dynamix::object* _d_obj ) \
    {\
        return I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(*_d_obj ); \
    }\

#define I_DYNAMIX_MESSAGE0_MULTI(export, message_name, method_name, return_type, constness ) \
    I_DYNAMIX_MESSAGE0_DECL(export, message_name, method_name, return_type, constness, multicast ) \
    /* step 4: define the message functions -> the one that will be called for the objects */ \
    /* function A: concrete combinator */ \
    template <typename Combinator> \
    void method_name(constness ::dynamix::object& _d_obj , Combinator& _d_combinator) \
    { \
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_combinator_call(_d_obj, _d_combinator ); \
    } \
    /* function B: template combinator -> can be called on a single line */ \
    template <template <typename> class Combinator> \
    typename Combinator<return_type>::result_type method_name(constness ::dynamix::object& _d_obj ) \
    { \
        Combinator<return_type> _d_combinator; \
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_combinator_call(_d_obj, _d_combinator ); \
        return _d_combinator.result(); \
    } \
    /* function C: no combinator */ \
    inline void method_name(constness ::dynamix::object& _d_obj ) \
    { \
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(_d_obj ); \
    } \
    /* also define a pointer function with no combinator */ \
    inline void method_name(constness ::dynamix::object* _d_obj ) \
    {\
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(*_d_obj ); \
    }\


#define I_DYNAMIX_MESSAGE1_DECL(export, message_name, method_name, return_type, constness, message_mechanism , arg0_type, a0) \
    /* mechanism shows whether it's a multicast or unicast */ \
    \
    /* step 1: define the message struct */ \
    struct export I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name) : public ::dynamix::internal::I_DYNAMIX_MESSAGE_CALLER_STRUCT(message_mechanism) \
        <I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name), constness ::dynamix::object, return_type , arg0_type> \
    { \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)() \
            : I_DYNAMIX_MESSAGE_CALLER_STRUCT(message_mechanism)(I_DYNAMIX_PP_STRINGIZE(message_name)) \
        {} \
        /* MethodOwner is the actual owner of the message (either the mixin or one of its parents) */ \
        template <typename Mixin, typename MethodOwner> \
        ::dynamix::internal::func_ptr get_caller_for() const \
        { \
            /* prevent the linker from optimizing away the caller function */ \
            static caller_func the_caller = I_DYNAMIX_CALLER_NAME(constness)<Mixin, MethodOwner, &MethodOwner::method_name>; \
            /* cast the caller to a void (*)() - safe according to the standard */ \
            return reinterpret_cast< ::dynamix::internal::func_ptr>(the_caller); \
        } \
    }; \
    /* step 2: define a message tag, that will be used to identify the message in feature lists */ \
    /* it would have been nice if we could set this global variable to the unique global instance of the feature*/ \
    /* but unfortunately we cannot trust dynamic libraries to keep it straight for us */ \
    /* hence we rely on a getter like the mixin one */ \
    extern export I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name) * I_DYNAMIX_MESSAGE_TAG(message_name); \
    /* step 3: declare the feature getter and manual registrator for the message */ \
    extern export ::dynamix::feature& _dynamix_get_mixin_feature_safe(const I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)*); \
    extern export const ::dynamix::feature& _dynamix_get_mixin_feature_fast(const I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)*); \
    extern export void _dynamix_register_mixin_feature(const I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)*); \

#define I_DYNAMIX_MESSAGE1_UNI(export, message_name, method_name, return_type, constness , arg0_type, a0) \
    I_DYNAMIX_MESSAGE1_DECL(export, message_name, method_name, return_type, constness, unicast , arg0_type, a0) \
    /* step 4: define the message function -> the one that will be called for the objects */ \
    inline return_type method_name(constness ::dynamix::object& _d_obj , arg0_type a0) \
    {\
        return I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(_d_obj , std::forward<arg0_type>(a0)); \
    }\
    /* also define a pointer function */ \
    inline return_type method_name(constness ::dynamix::object* _d_obj , arg0_type a0) \
    {\
        return I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(*_d_obj , std::forward<arg0_type>(a0)); \
    }\

#define I_DYNAMIX_MESSAGE1_MULTI(export, message_name, method_name, return_type, constness , arg0_type, a0) \
    I_DYNAMIX_MESSAGE1_DECL(export, message_name, method_name, return_type, constness, multicast , arg0_type, a0) \
    /* step 4: define the message functions -> the one that will be called for the objects */ \
    /* function A: concrete combinator */ \
    template <typename Combinator> \
    void method_name(constness ::dynamix::object& _d_obj , arg0_type a0, Combinator& _d_combinator) \
    { \
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_combinator_call(_d_obj, _d_combinator , a0); \
    } \
    /* function B: template combinator -> can be called on a single line */ \
    template <template <typename> class Combinator> \
    typename Combinator<return_type>::result_type method_name(constness ::dynamix::object& _d_obj , arg0_type a0) \
    { \
        Combinator<return_type> _d_combinator; \
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_combinator_call(_d_obj, _d_combinator , a0); \
        return _d_combinator.result(); \
    } \
    /* function C: no combinator */ \
    inline void method_name(constness ::dynamix::object& _d_obj , arg0_type a0) \
    { \
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(_d_obj , a0); \
    } \
    /* also define a pointer function with no combinator */ \
    inline void method_name(constness ::dynamix::object* _d_obj , arg0_type a0) \
    {\
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(*_d_obj , a0); \
    }\


#define I_DYNAMIX_MESSAGE2_DECL(export, message_name, method_name, return_type, constness, message_mechanism , arg0_type, a0, arg1_type, a1) \
    /* mechanism shows whether it's a multicast or unicast */ \
    \
    /* step 1: define the message struct */ \
    struct export I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name) : public ::dynamix::internal::I_DYNAMIX_MESSAGE_CALLER_STRUCT(message_mechanism) \
        <I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name), constness ::dynamix::object, return_type , arg0_type, arg1_type> \
    { \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)() \
            : I_DYNAMIX_MESSAGE_CALLER_STRUCT(message_mechanism)(I_DYNAMIX_PP_STRINGIZE(message_name)) \
        {} \
        /* MethodOwner is the actual owner of the message (either the mixin or one of its parents) */ \
        template <typename Mixin, typename MethodOwner> \
        ::dynamix::internal::func_ptr get_caller_for() const \
        { \
            /* prevent the linker from optimizing away the caller function */ \
            static caller_func the_caller = I_DYNAMIX_CALLER_NAME(constness)<Mixin, MethodOwner, &MethodOwner::method_name>; \
            /* cast the caller to a void (*)() - safe according to the standard */ \
            return reinterpret_cast< ::dynamix::internal::func_ptr>(the_caller); \
        } \
    }; \
    /* step 2: define a message tag, that will be used to identify the message in feature lists */ \
    /* it would have been nice if we could set this global variable to the unique global instance of the feature*/ \
    /* but unfortunately we cannot trust dynamic libraries to keep it straight for us */ \
    /* hence we rely on a getter like the mixin one */ \
    extern export I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name) * I_DYNAMIX_MESSAGE_TAG(message_name); \
    /* step 3: declare the feature getter and manual registrator for the message */ \
    extern export ::dynamix::feature& _dynamix_get_mixin_feature_safe(const I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)*); \
    extern export const ::dynamix::feature& _dynamix_get_mixin_feature_fast(const I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)*); \
    extern export void _dynamix_register_mixin_feature(const I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)*); \

#define I_DYNAMIX_MESSAGE2_UNI(export, message_name, method_name, return_type, constness , arg0_type, a0, arg1_type, a1) \
    I_DYNAMIX_MESSAGE2_DECL(export, message_name, method_name, return_type, constness, unicast , arg0_type, a0, arg1_type, a1) \
    /* step 4: define the message function -> the one that will be called for the objects */ \
    inline return_type method_name(constness ::dynamix::object& _d_obj , arg0_type a0, arg1_type a1) \
    {\
        return I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(_d_obj , std::forward<arg0_type>(a0), std::forward<arg1_type>(a1)); \
    }\
    /* also define a pointer function */ \
    inline return_type method_name(constness ::dynamix::object* _d_obj , arg0_type a0, arg1_type a1) \
    {\
        return I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(*_d_obj , std::forward<arg0_type>(a0), std::forward<arg1_type>(a1)); \
    }\

#define I_DYNAMIX_MESSAGE2_MULTI(export, message_name, method_name, return_type, constness , arg0_type, a0, arg1_type, a1) \
    I_DYNAMIX_MESSAGE2_DECL(export, message_name, method_name, return_type, constness, multicast , arg0_type, a0, arg1_type, a1) \
    /* step 4: define the message functions -> the one that will be called for the objects */ \
    /* function A: concrete combinator */ \
    template <typename Combinator> \
    void method_name(constness ::dynamix::object& _d_obj , arg0_type a0, arg1_type a1, Combinator& _d_combinator) \
    { \
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_combinator_call(_d_obj, _d_combinator , a0, a1); \
    } \
    /* function B: template combinator -> can be called on a single line */ \
    template <template <typename> class Combinator> \
    typename Combinator<return_type>::result_type method_name(constness ::dynamix::object& _d_obj , arg0_type a0, arg1_type a1) \
    { \
        Combinator<return_type> _d_combinator; \
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_combinator_call(_d_obj, _d_combinator , a0, a1); \
        return _d_combinator.result(); \
    } \
    /* function C: no combinator */ \
    inline void method_name(constness ::dynamix::object& _d_obj , arg0_type a0, arg1_type a1) \
    { \
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(_d_obj , a0, a1); \
    } \
    /* also define a pointer function with no combinator */ \
    inline void method_name(constness ::dynamix::object* _d_obj , arg0_type a0, arg1_type a1) \
    {\
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(*_d_obj , a0, a1); \
    }\


#define I_DYNAMIX_MESSAGE3_DECL(export, message_name, method_name, return_type, constness, message_mechanism , arg0_type, a0, arg1_type, a1, arg2_type, a2) \
    /* mechanism shows whether it's a multicast or unicast */ \
    \
    /* step 1: define the message struct */ \
    struct export I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name) : public ::dynamix::internal::I_DYNAMIX_MESSAGE_CALLER_STRUCT(message_mechanism) \
        <I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name), constness ::dynamix::object, return_type , arg0_type, arg1_type, arg2_type> \
    { \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)() \
            : I_DYNAMIX_MESSAGE_CALLER_STRUCT(message_mechanism)(I_DYNAMIX_PP_STRINGIZE(message_name)) \
        {} \
        /* MethodOwner is the actual owner of the message (either the mixin or one of its parents) */ \
        template <typename Mixin, typename MethodOwner> \
        ::dynamix::internal::func_ptr get_caller_for() const \
        { \
            /* prevent the linker from optimizing away the caller function */ \
            static caller_func the_caller = I_DYNAMIX_CALLER_NAME(constness)<Mixin, MethodOwner, &MethodOwner::method_name>; \
            /* cast the caller to a void (*)() - safe according to the standard */ \
            return reinterpret_cast< ::dynamix::internal::func_ptr>(the_caller); \
        } \
    }; \
    /* step 2: define a message tag, that will be used to identify the message in feature lists */ \
    /* it would have been nice if we could set this global variable to the unique global instance of the feature*/ \
    /* but unfortunately we cannot trust dynamic libraries to keep it straight for us */ \
    /* hence we rely on a getter like the mixin one */ \
    extern export I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name) * I_DYNAMIX_MESSAGE_TAG(message_name); \
    /* step 3: declare the feature getter and manual registrator for the message */ \
    extern export ::dynamix::feature& _dynamix_get_mixin_feature_safe(const I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)*); \
    extern export const ::dynamix::feature& _dynamix_get_mixin_feature_fast(const I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)*); \
    extern export void _dynamix_register_mixin_feature(const I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)*); \

#define I_DYNAMIX_MESSAGE3_UNI(export, message_name, method_name, return_type, constness , arg0_type, a0, arg1_type, a1, arg2_type, a2) \
    I_DYNAMIX_MESSAGE3_DECL(export, message_name, method_name, return_type, constness, unicast , arg0_type, a0, arg1_type, a1, arg2_type, a2) \
    /* step 4: define the message function -> the one that will be called for the objects */ \
    inline return_type method_name(constness ::dynamix::object& _d_obj , arg0_type a0, arg1_type a1, arg2_type a2) \
    {\
        return I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(_d_obj , std::forward<arg0_type>(a0), std::forward<arg1_type>(a1), std::forward<arg2_type>(a2)); \
    }\
    /* also define a pointer function */ \
    inline return_type method_name(constness ::dynamix::object* _d_obj , arg0_type a0, arg1_type a1, arg2_type a2) \
    {\
        return I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(*_d_obj , std::forward<arg0_type>(a0), std::forward<arg1_type>(a1), std::forward<arg2_type>(a2)); \
    }\

#define I_DYNAMIX_MESSAGE3_MULTI(export, message_name, method_name, return_type, constness , arg0_type, a0, arg1_type, a1, arg2_type, a2) \
    I_DYNAMIX_MESSAGE3_DECL(export, message_name, method_name, return_type, constness, multicast , arg0_type, a0, arg1_type, a1, arg2_type, a2) \
    /* step 4: define the message functions -> the one that will be called for the objects */ \
    /* function A: concrete combinator */ \
    template <typename Combinator> \
    void method_name(constness ::dynamix::object& _d_obj , arg0_type a0, arg1_type a1, arg2_type a2, Combinator& _d_combinator) \
    { \
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_combinator_call(_d_obj, _d_combinator , a0, a1, a2); \
    } \
    /* function B: template combinator -> can be called on a single line */ \
    template <template <typename> class Combinator> \
    typename Combinator<return_type>::result_type method_name(constness ::dynamix::object& _d_obj , arg0_type a0, arg1_type a1, arg2_type a2) \
    { \
        Combinator<return_type> _d_combinator; \
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_combinator_call(_d_obj, _d_combinator , a0, a1, a2); \
        return _d_combinator.result(); \
    } \
    /* function C: no combinator */ \
    inline void method_name(constness ::dynamix::object& _d_obj , arg0_type a0, arg1_type a1, arg2_type a2) \
    { \
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(_d_obj , a0, a1, a2); \
    } \
    /* also define a pointer function with no combinator */ \
    inline void method_name(constness ::dynamix::object* _d_obj , arg0_type a0, arg1_type a1, arg2_type a2) \
    {\
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(*_d_obj , a0, a1, a2); \
    }\


#define I_DYNAMIX_MESSAGE4_DECL(export, message_name, method_name, return_type, constness, message_mechanism , arg0_type, a0, arg1_type, a1, arg2_type, a2, arg3_type, a3) \
    /* mechanism shows whether it's a multicast or unicast */ \
    \
    /* step 1: define the message struct */ \
    struct export I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name) : public ::dynamix::internal::I_DYNAMIX_MESSAGE_CALLER_STRUCT(message_mechanism) \
        <I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name), constness ::dynamix::object, return_type , arg0_type, arg1_type, arg2_type, arg3_type> \
    { \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)() \
            : I_DYNAMIX_MESSAGE_CALLER_STRUCT(message_mechanism)(I_DYNAMIX_PP_STRINGIZE(message_name)) \
        {} \
        /* MethodOwner is the actual owner of the message (either the mixin or one of its parents) */ \
        template <typename Mixin, typename MethodOwner> \
        ::dynamix::internal::func_ptr get_caller_for() const \
        { \
            /* prevent the linker from optimizing away the caller function */ \
            static caller_func the_caller = I_DYNAMIX_CALLER_NAME(constness)<Mixin, MethodOwner, &MethodOwner::method_name>; \
            /* cast the caller to a void (*)() - safe according to the standard */ \
            return reinterpret_cast< ::dynamix::internal::func_ptr>(the_caller); \
        } \
    }; \
    /* step 2: define a message tag, that will be used to identify the message in feature lists */ \
    /* it would have been nice if we could set this global variable to the unique global instance of the feature*/ \
    /* but unfortunately we cannot trust dynamic libraries to keep it straight for us */ \
    /* hence we rely on a getter like the mixin one */ \
    extern export I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name) * I_DYNAMIX_MESSAGE_TAG(message_name); \
    /* step 3: declare the feature getter and manual registrator for the message */ \
    extern export ::dynamix::feature& _dynamix_get_mixin_feature_safe(const I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)*); \
    extern export const ::dynamix::feature& _dynamix_get_mixin_feature_fast(const I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)*); \
    extern export void _dynamix_register_mixin_feature(const I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)*); \

#define I_DYNAMIX_MESSAGE4_UNI(export, message_name, method_name, return_type, constness , arg0_type, a0, arg1_type, a1, arg2_type, a2, arg3_type, a3) \
    I_DYNAMIX_MESSAGE4_DECL(export, message_name, method_name, return_type, constness, unicast , arg0_type, a0, arg1_type, a1, arg2_type, a2, arg3_type, a3) \
    /* step 4: define the message function -> the one that will be called for the objects */ \
    inline return_type method_name(constness ::dynamix::object& _d_obj , arg0_type a0, arg1_type a1, arg2_type a2, arg3_type a3) \
    {\
        return I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(_d_obj , std::forward<arg0_type>(a0), std::forward<arg1_type>(a1), std::forward<arg2_type>(a2), std::forward<arg3_type>(a3)); \
    }\
    /* also define a pointer function */ \
    inline return_type method_name(constness ::dynamix::object* _d_obj , arg0_type a0, arg1_type a1, arg2_type a2, arg3_type a3) \
    {\
        return I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(*_d_obj , std::forward<arg0_type>(a0), std::forward<arg1_type>(a1), std::forward<arg2_type>(a2), std::forward<arg3_type>(a3)); \
    }\

#define I_DYNAMIX_MESSAGE4_MULTI(export, message_name, method_name, return_type, constness , arg0_type, a0, arg1_type, a1, arg2_type, a2, arg3_type, a3) \
    I_DYNAMIX_MESSAGE4_DECL(export, message_name, method_name, return_type, constness, multicast , arg0_type, a0, arg1_type, a1, arg2_type, a2, arg3_type, a3) \
    /* step 4: define the message functions -> the one that will be called for the objects */ \
    /* function A: concrete combinator */ \
    template <typename Combinator> \
    void method_name(constness ::dynamix::object& _d_obj , arg0_type a0, arg1_type a1, arg2_type a2, arg3_type a3, Combinator& _d_combinator) \
    { \
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_combinator_call(_d_obj, _d_combinator , a0, a1, a2, a3); \
    } \
    /* function B: template combinator -> can be called on a single line */ \
    template <template <typename> class Combinator> \
    typename Combinator<return_type>::result_type method_name(constness ::dynamix::object& _d_obj , arg0_type a0, arg1_type a1, arg2_type a2, arg3_type a3) \
    { \
        Combinator<return_type> _d_combinator; \
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_combinator_call(_d_obj, _d_combinator , a0, a1, a2, a3); \
        return _d_combinator.result(); \
    } \
    /* function C: no combinator */ \
    inline void method_name(constness ::dynamix::object& _d_obj , arg0_type a0, arg1_type a1, arg2_type a2, arg3_type a3) \
    { \
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(_d_obj , a0, a1, a2, a3); \
    } \
    /* also define a pointer function with no combinator */ \
    inline void method_name(constness ::dynamix::object* _d_obj , arg0_type a0, arg1_type a1, arg2_type a2, arg3_type a3) \
    {\
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(*_d_obj , a0, a1, a2, a3); \
    }\


#define I_DYNAMIX_MESSAGE5_DECL(export, message_name, method_name, return_type, constness, message_mechanism , arg0_type, a0, arg1_type, a1, arg2_type, a2, arg3_type, a3, arg4_type, a4) \
    /* mechanism shows whether it's a multicast or unicast */ \
    \
    /* step 1: define the message struct */ \
    struct export I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name) : public ::dynamix::internal::I_DYNAMIX_MESSAGE_CALLER_STRUCT(message_mechanism) \
        <I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name), constness ::dynamix::object, return_type , arg0_type, arg1_type, arg2_type, arg3_type, arg4_type> \
    { \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)() \
            : I_DYNAMIX_MESSAGE_CALLER_STRUCT(message_mechanism)(I_DYNAMIX_PP_STRINGIZE(message_name)) \
        {} \
        /* MethodOwner is the actual owner of the message (either the mixin or one of its parents) */ \
        template <typename Mixin, typename MethodOwner> \
        ::dynamix::internal::func_ptr get_caller_for() const \
        { \
            /* prevent the linker from optimizing away the caller function */ \
            static caller_func the_caller = I_DYNAMIX_CALLER_NAME(constness)<Mixin, MethodOwner, &MethodOwner::method_name>; \
            /* cast the caller to a void (*)() - safe according to the standard */ \
            return reinterpret_cast< ::dynamix::internal::func_ptr>(the_caller); \
        } \
    }; \
    /* step 2: define a message tag, that will be used to identify the message in feature lists */ \
    /* it would have been nice if we could set this global variable to the unique global instance of the feature*/ \
    /* but unfortunately we cannot trust dynamic libraries to keep it straight for us */ \
    /* hence we rely on a getter like the mixin one */ \
    extern export I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name) * I_DYNAMIX_MESSAGE_TAG(message_name); \
    /* step 3: declare the feature getter and manual registrator for the message */ \
    extern export ::dynamix::feature& _dynamix_get_mixin_feature_safe(const I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)*); \
    extern export const ::dynamix::feature& _dynamix_get_mixin_feature_fast(const I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)*); \
    extern export void _dynamix_register_mixin_feature(const I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)*); \

#define I_DYNAMIX_MESSAGE5_UNI(export, message_name, method_name, return_type, constness , arg0_type, a0, arg1_type, a1, arg2_type, a2, arg3_type, a3, arg4_type, a4) \
    I_DYNAMIX_MESSAGE5_DECL(export, message_name, method_name, return_type, constness, unicast , arg0_type, a0, arg1_type, a1, arg2_type, a2, arg3_type, a3, arg4_type, a4) \
    /* step 4: define the message function -> the one that will be called for the objects */ \
    inline return_type method_name(constness ::dynamix::object& _d_obj , arg0_type a0, arg1_type a1, arg2_type a2, arg3_type a3, arg4_type a4) \
    {\
        return I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(_d_obj , std::forward<arg0_type>(a0), std::forward<arg1_type>(a1), std::forward<arg2_type>(a2), std::forward<arg3_type>(a3), std::forward<arg4_type>(a4)); \
    }\
    /* also define a pointer function */ \
    inline return_type method_name(constness ::dynamix::object* _d_obj , arg0_type a0, arg1_type a1, arg2_type a2, arg3_type a3, arg4_type a4) \
    {\
        return I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(*_d_obj , std::forward<arg0_type>(a0), std::forward<arg1_type>(a1), std::forward<arg2_type>(a2), std::forward<arg3_type>(a3), std::forward<arg4_type>(a4)); \
    }\

#define I_DYNAMIX_MESSAGE5_MULTI(export, message_name, method_name, return_type, constness , arg0_type, a0, arg1_type, a1, arg2_type, a2, arg3_type, a3, arg4_type, a4) \
    I_DYNAMIX_MESSAGE5_DECL(export, message_name, method_name, return_type, constness, multicast , arg0_type, a0, arg1_type, a1, arg2_type, a2, arg3_type, a3, arg4_type, a4) \
    /* step 4: define the message functions -> the one that will be called for the objects */ \
    /* function A: concrete combinator */ \
    template <typename Combinator> \
    void method_name(constness ::dynamix::object& _d_obj , arg0_type a0, arg1_type a1, arg2_type a2, arg3_type a3, arg4_type a4, Combinator& _d_combinator) \
    { \
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_combinator_call(_d_obj, _d_combinator , a0, a1, a2, a3, a4); \
    } \
    /* function B: template combinator -> can be called on a single line */ \
    template <template <typename> class Combinator> \
    typename Combinator<return_type>::result_type method_name(constness ::dynamix::object& _d_obj , arg0_type a0, arg1_type a1, arg2_type a2, arg3_type a3, arg4_type a4) \
    { \
        Combinator<return_type> _d_combinator; \
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_combinator_call(_d_obj, _d_combinator , a0, a1, a2, a3, a4); \
        return _d_combinator.result(); \
    } \
    /* function C: no combinator */ \
    inline void method_name(constness ::dynamix::object& _d_obj , arg0_type a0, arg1_type a1, arg2_type a2, arg3_type a3, arg4_type a4) \
    { \
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(_d_obj , a0, a1, a2, a3, a4); \
    } \
    /* also define a pointer function with no combinator */ \
    inline void method_name(constness ::dynamix::object* _d_obj , arg0_type a0, arg1_type a1, arg2_type a2, arg3_type a3, arg4_type a4) \
    {\
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(*_d_obj , a0, a1, a2, a3, a4); \
    }\


#define I_DYNAMIX_MESSAGE6_DECL(export, message_name, method_name, return_type, constness, message_mechanism , arg0_type, a0, arg1_type, a1, arg2_type, a2, arg3_type, a3, arg4_type, a4, arg5_type, a5) \
    /* mechanism shows whether it's a multicast or unicast */ \
    \
    /* step 1: define the message struct */ \
    struct export I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name) : public ::dynamix::internal::I_DYNAMIX_MESSAGE_CALLER_STRUCT(message_mechanism) \
        <I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name), constness ::dynamix::object, return_type , arg0_type, arg1_type, arg2_type, arg3_type, arg4_type, arg5_type> \
    { \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)() \
            : I_DYNAMIX_MESSAGE_CALLER_STRUCT(message_mechanism)(I_DYNAMIX_PP_STRINGIZE(message_name)) \
        {} \
        /* MethodOwner is the actual owner of the message (either the mixin or one of its parents) */ \
        template <typename Mixin, typename MethodOwner> \
        ::dynamix::internal::func_ptr get_caller_for() const \
        { \
            /* prevent the linker from optimizing away the caller function */ \
            static caller_func the_caller = I_DYNAMIX_CALLER_NAME(constness)<Mixin, MethodOwner, &MethodOwner::method_name>; \
            /* cast the caller to a void (*)() - safe according to the standard */ \
            return reinterpret_cast< ::dynamix::internal::func_ptr>(the_caller); \
        } \
    }; \
    /* step 2: define a message tag, that will be used to identify the message in feature lists */ \
    /* it would have been nice if we could set this global variable to the unique global instance of the feature*/ \
    /* but unfortunately we cannot trust dynamic libraries to keep it straight for us */ \
    /* hence we rely on a getter like the mixin one */ \
    extern export I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name) * I_DYNAMIX_MESSAGE_TAG(message_name); \
    /* step 3: declare the feature getter and manual registrator for the message */ \
    extern export ::dynamix::feature& _dynamix_get_mixin_feature_safe(const I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)*); \
    extern export const ::dynamix::feature& _dynamix_get_mixin_feature_fast(const I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)*); \
    extern export void _dynamix_register_mixin_feature(const I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)*); \

#define I_DYNAMIX_MESSAGE6_UNI(export, message_name, method_name, return_type, constness , arg0_type, a0, arg1_type, a1, arg2_type, a2, arg3_type, a3, arg4_type, a4, arg5_type, a5) \
    I_DYNAMIX_MESSAGE6_DECL(export, message_name, method_name, return_type, constness, unicast , arg0_type, a0, arg1_type, a1, arg2_type, a2, arg3_type, a3, arg4_type, a4, arg5_type, a5) \
    /* step 4: define the message function -> the one that will be called for the objects */ \
    inline return_type method_name(constness ::dynamix::object& _d_obj , arg0_type a0, arg1_type a1, arg2_type a2, arg3_type a3, arg4_type a4, arg5_type a5) \
    {\
        return I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(_d_obj , std::forward<arg0_type>(a0), std::forward<arg1_type>(a1), std::forward<arg2_type>(a2), std::forward<arg3_type>(a3), std::forward<arg4_type>(a4), std::forward<arg5_type>(a5)); \
    }\
    /* also define a pointer function */ \
    inline return_type method_name(constness ::dynamix::object* _d_obj , arg0_type a0, arg1_type a1, arg2_type a2, arg3_type a3, arg4_type a4, arg5_type a5) \
    {\
        return I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(*_d_obj , std::forward<arg0_type>(a0), std::forward<arg1_type>(a1), std::forward<arg2_type>(a2), std::forward<arg3_type>(a3), std::forward<arg4_type>(a4), std::forward<arg5_type>(a5)); \
    }\

#define I_DYNAMIX_MESSAGE6_MULTI(export, message_name, method_name, return_type, constness , arg0_type, a0, arg1_type, a1, arg2_type, a2, arg3_type, a3, arg4_type, a4, arg5_type, a5) \
    I_DYNAMIX_MESSAGE6_DECL(export, message_name, method_name, return_type, constness, multicast , arg0_type, a0, arg1_type, a1, arg2_type, a2, arg3_type, a3, arg4_type, a4, arg5_type, a5) \
    /* step 4: define the message functions -> the one that will be called for the objects */ \
    /* function A: concrete combinator */ \
    template <typename Combinator> \
    void method_name(constness ::dynamix::object& _d_obj , arg0_type a0, arg1_type a1, arg2_type a2, arg3_type a3, arg4_type a4, arg5_type a5, Combinator& _d_combinator) \
    { \
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_combinator_call(_d_obj, _d_combinator , a0, a1, a2, a3, a4, a5); \
    } \
    /* function B: template combinator -> can be called on a single line */ \
    template <template <typename> class Combinator> \
    typename Combinator<return_type>::result_type method_name(constness ::dynamix::object& _d_obj , arg0_type a0, arg1_type a1, arg2_type a2, arg3_type a3, arg4_type a4, arg5_type a5) \
    { \
        Combinator<return_type> _d_combinator; \
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_combinator_call(_d_obj, _d_combinator , a0, a1, a2, a3, a4, a5); \
        return _d_combinator.result(); \
    } \
    /* function C: no combinator */ \
    inline void method_name(constness ::dynamix::object& _d_obj , arg0_type a0, arg1_type a1, arg2_type a2, arg3_type a3, arg4_type a4, arg5_type a5) \
    { \
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(_d_obj , a0, a1, a2, a3, a4, a5); \
    } \
    /* also define a pointer function with no combinator */ \
    inline void method_name(constness ::dynamix::object* _d_obj , arg0_type a0, arg1_type a1, arg2_type a2, arg3_type a3, arg4_type a4, arg5_type a5) \
    {\
        /* not forwarded arguments. We DO want an error if some of them are rvalue references */ \
        I_DYNAMIX_MESSAGE_STRUCT_NAME(message_name)::make_call(*_d_obj , a0, a1, a2, a3, a4, a5); \
    }\

#include "arity_message_macros.hpp"
