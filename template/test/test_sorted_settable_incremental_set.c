#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

struct object {
    const struct butterflyfish_sorted_settable_incremental_set_$t$ *const
            sorted_settable_incremental_set_$t$;
    const struct butterflyfish_settable_incremental_set_$t$ *const
            settable_incremental_set_$t$;
    const struct butterflyfish_sorted_incremental_set_$t$ *const
            sorted_incremental_set_$t$;
    const struct butterflyfish_sorted_settable_set_$t$ *const
            sorted_settable_set_$t$;
    const struct butterflyfish_incremental_set_$t$ *const incremental_set_$t$;
    const struct butterflyfish_settable_set_$t$ *const settable_set_$t$;
    const struct butterflyfish_sorted_set_$t$ *const sorted_set_$t$;
    const struct butterflyfish_addable_$t$ *const addable_$t$;
    const struct butterflyfish_settable_$t$ *const settable_$t$;
    const struct butterflyfish_set_$t$ *const set_$t$;
    const struct butterflyfish_sorted_$t$ *const sorted_$t$;
    const struct butterflyfish_collection_$t$ *const collection_$t$;
    const struct butterflyfish_stream_$t$ *const stream_$t$;
};

static int stream_first(const struct butterflyfish_stream_$t$ *const object,
                        const $v$*const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int stream_next(const struct butterflyfish_stream_$t$ *const object,
                       const $v$const item,
                       const $v$*const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_stream_$t$ stream_$t$ = {
        .first = stream_first,
        .next = stream_next
};

static int as_stream(const struct butterflyfish_collection_$t$ *const object,
                     const struct butterflyfish_stream_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, collection_$t$, stream_$t$);
    return 0;
}

static int
collection_last(const struct butterflyfish_collection_$t$ *const object,
                const $v$*const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int
collection_prev(const struct butterflyfish_collection_$t$ *const object,
                const $v$const item,
                const $v$*const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

static int
collection_count(const struct butterflyfish_collection_$t$ *const object,
                 uintmax_t *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    *out = mock();
    return 0;
}

const struct butterflyfish_collection_$t$ collection_$t$ = {
        .as_stream = as_stream,
        .last = collection_last,
        .prev = collection_prev,
        .count = collection_count,
};

static int
sorted_as_collection(const struct butterflyfish_sorted_$t$ *const object,
                     const struct butterflyfish_collection_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, sorted_$t$, collection_$t$);
    return 0;
}

static int
sorted_ceiling(const struct butterflyfish_sorted_$t$ *const object,
               const $v$const value,
               const $v$*const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static int
sorted_floor(const struct butterflyfish_sorted_$t$ *const object,
             const $v$const value,
             const $v$*const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static int
sorted_higher(const struct butterflyfish_sorted_$t$ *const object,
              const $v$const value,
              const $v$*const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static int
sorted_lower(const struct butterflyfish_sorted_$t$ *const object,
             const $v$const value,
             const $v$*const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_sorted_$t$ sorted_$t$ = {
        .as_collection = sorted_as_collection,
        .ceiling = sorted_ceiling,
        .floor = sorted_floor,
        .higher = sorted_higher,
        .lower = sorted_lower
};

static int
set_as_collection(const struct butterflyfish_set_$t$ *const object,
                  const struct butterflyfish_collection_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, set_$t$, collection_$t$);
    return 0;
}

static int set_contains(const struct butterflyfish_set_$t$ *const object,
                        const $v$const value,
                        bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static int set_contains_all(const struct butterflyfish_set_$t$ *const object,
                            const struct butterflyfish_stream_$t$ *const other,
                            bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    assert_non_null(out);
    return mock();
}

static int set_get(const struct butterflyfish_set_$t$ *const object,
                   const $v$const value,
                   const $v$*const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_set_$t$ set_$t$ = {
        .as_collection = set_as_collection,
        .contains = set_contains,
        .contains_all = set_contains_all,
        .get = set_get
};

static int
settable_as_collection(const struct butterflyfish_settable_$t$ *const object,
                       const struct butterflyfish_collection_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, settable_$t$, collection_$t$);
    return 0;
}

static int
settable_set_item(struct butterflyfish_settable_$t$ *const object,
                  const $v$const item,
                  const $v$const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(value);
    return mock();
}

const struct butterflyfish_settable_$t$ settable_$t$ = {
        .as_collection = settable_as_collection,
        .set_item = settable_set_item,
};

static int
addable_as_collection(const struct butterflyfish_addable_$t$ *const object,
                      const struct butterflyfish_collection_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, addable_$t$, collection_$t$);
    return 0;
}

static int
addable_add(struct butterflyfish_addable_$t$ *const object,
            const $v$const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    return mock();
}

static int
addable_add_all(struct butterflyfish_addable_$t$ *const object,
                const struct butterflyfish_stream_$t$ *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

const struct butterflyfish_addable_$t$ addable_$t$ = {
        .as_collection = addable_as_collection,
        .add = addable_add,
        .add_all = addable_add_all,
};

static int
sorted_set_as_sorted(const struct butterflyfish_sorted_set_$t$ *const object,
                     const struct butterflyfish_sorted_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, sorted_set_$t$, sorted_$t$);
    return 0;
}

static int
sorted_set_as_set(const struct butterflyfish_sorted_set_$t$ *const object,
                  const struct butterflyfish_set_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, sorted_set_$t$, set_$t$);
    return 0;
}

const struct butterflyfish_sorted_set_$t$ sorted_set_$t$ = {
        .as_sorted = sorted_set_as_sorted,
        .as_set = sorted_set_as_set,
};

static int
settable_set_as_set(const struct butterflyfish_settable_set_$t$ *const object,
                    const struct butterflyfish_set_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, settable_set_$t$, set_$t$);
    return 0;
}

static int
settable_set_as_settable(struct butterflyfish_settable_set_$t$ *const object,
                         struct butterflyfish_settable_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, settable_set_$t$,
                              settable_$t$);
    return 0;
}

static int
settable_set_set(struct butterflyfish_settable_set_$t$ *const object,
                 const $v$const item,
                 const $v$const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(value);
    return mock();
}

const struct butterflyfish_settable_set_$t$ settable_set_$t$ = {
        .as_settable = settable_set_as_settable,
        .as_set = settable_set_as_set,
        .set = settable_set_set,
};

static int
incremental_set_as_addable(
        struct butterflyfish_incremental_set_$t$ *const object,
        struct butterflyfish_addable_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, incremental_set_$t$,
                              addable_$t$);
    return 0;
}

static int
incremental_set_as_set(
        const struct butterflyfish_incremental_set_$t$ *const object,
        const struct butterflyfish_set_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, incremental_set_$t$, set_$t$);
    return 0;
}

const struct butterflyfish_incremental_set_$t$ incremental_set_$t$ = {
        .as_addable = incremental_set_as_addable,
        .as_set = incremental_set_as_set,
};

static int
sorted_settable_set_as_settable_set(
        struct butterflyfish_sorted_settable_set_$t$ *const object,
        struct butterflyfish_settable_set_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, sorted_settable_set_$t$,
                              settable_set_$t$);
    return 0;
}

static int
sorted_settable_set_as_sorted_set(
        const struct butterflyfish_sorted_settable_set_$t$ *const object,
        const struct butterflyfish_sorted_set_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, sorted_settable_set_$t$,
                              sorted_set_$t$);
    return 0;
}

const struct butterflyfish_sorted_settable_set_$t$ sorted_settable_set_$t$ = {
        .as_settable_set = sorted_settable_set_as_settable_set,
        .as_sorted_set = sorted_settable_set_as_sorted_set,
};

static int
sorted_incremental_set_as_incremental_set(
        struct butterflyfish_sorted_incremental_set_$t$ *const object,
        struct butterflyfish_incremental_set_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, sorted_incremental_set_$t$,
                              incremental_set_$t$);
    return 0;
}

static int
sorted_incremental_set_as_sorted_set(
        const struct butterflyfish_sorted_incremental_set_$t$ *const object,
        const struct butterflyfish_sorted_set_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, sorted_incremental_set_$t$,
                              sorted_set_$t$);
    return 0;
}

const struct
butterflyfish_sorted_incremental_set_$t$ sorted_incremental_set_$t$ = {
        .as_incremental_set = sorted_incremental_set_as_incremental_set,
        .as_sorted_set = sorted_incremental_set_as_sorted_set,
};

static int
settable_incremental_set_as_incremental_set(
        struct butterflyfish_settable_incremental_set_$t$ *const object,
        struct butterflyfish_incremental_set_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            settable_incremental_set_$t$, incremental_set_$t$);
    return 0;
}

static int
settable_incremental_set_as_settable_set(
        struct butterflyfish_settable_incremental_set_$t$ *const object,
        struct butterflyfish_settable_set_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            settable_incremental_set_$t$, settable_set_$t$);
    return 0;
}

const struct
butterflyfish_settable_incremental_set_$t$ settable_incremental_set_$t$ = {
        .as_incremental_set = settable_incremental_set_as_incremental_set,
        .as_settable_set = settable_incremental_set_as_settable_set,
};

static int
sorted_settable_incremental_set_as_settable_incremental_set(
        struct butterflyfish_sorted_settable_incremental_set_$t$ *const object,
        struct butterflyfish_settable_incremental_set_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              sorted_settable_incremental_set_$t$,
                              settable_incremental_set_$t$);
    return 0;
}

static int
sorted_settable_incremental_set_as_sorted_incremental_set(
        struct butterflyfish_sorted_settable_incremental_set_$t$ *const object,
        struct butterflyfish_sorted_incremental_set_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              sorted_settable_incremental_set_$t$,
                              sorted_incremental_set_$t$);
    return 0;
}

static int
sorted_settable_incremental_set_as_sorted_settable_set(
        struct butterflyfish_sorted_settable_incremental_set_$t$ *const object,
        struct butterflyfish_sorted_settable_set_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              sorted_settable_incremental_set_$t$,
                              sorted_settable_set_$t$);
    return 0;
}

const struct butterflyfish_sorted_settable_incremental_set_$t$
sorted_settable_incremental_set_$t$ = {
        .as_settable_incremental_set =
                sorted_settable_incremental_set_as_settable_incremental_set,
        .as_sorted_incremental_set =
                sorted_settable_incremental_set_as_sorted_incremental_set,
        .as_sorted_settable_set =
                sorted_settable_incremental_set_as_sorted_settable_set,
};

static void check_as_stream_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_as_stream(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_stream_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_as_stream(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_stream(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance + offsetof(struct object, stream_$t$);
    const struct butterflyfish_stream_$t$ *out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_$t$_as_stream(
            (const struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_collection_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_as_collection(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_collection_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_as_collection(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_collection(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
            + offsetof(struct object, collection_$t$);
    const struct butterflyfish_collection_$t$ *out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_$t$_as_collection(
            (const struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_sorted_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_as_sorted(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_sorted_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_as_sorted(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_sorted(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance + offsetof(struct object, sorted_$t$);
    const struct butterflyfish_sorted_$t$ *out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_$t$_as_sorted(
            (const struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_as_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_as_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_set(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance + offsetof(struct object, set_$t$);
    const struct butterflyfish_set_$t$ *out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_$t$_as_set(
            (const struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_settable_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_as_settable(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_settable_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_as_settable(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_settable(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
            + offsetof(struct object, settable_$t$);
    struct butterflyfish_settable_$t$ *out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_$t$_as_settable(
            (struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_addable_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_as_addable(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_addable_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_as_addable(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_addable(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
            + offsetof(struct object, addable_$t$);
    struct butterflyfish_addable_$t$ *out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_$t$_as_addable(
            (struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_sorted_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_as_sorted_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_sorted_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_as_sorted_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_sorted_set(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
            + offsetof(struct object, sorted_set_$t$);
    const struct butterflyfish_sorted_set_$t$ *out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_$t$_as_sorted_set(
            (const struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_settable_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_as_settable_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_settable_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_as_settable_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_settable_set(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
            + offsetof(struct object, settable_set_$t$);
    struct butterflyfish_settable_set_$t$ *out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_$t$_as_settable_set(
            (struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_incremental_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_as_incremental_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_incremental_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_as_incremental_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_incremental_set(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
            + offsetof(struct object, incremental_set_$t$);
    struct butterflyfish_incremental_set_$t$ *out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_$t$_as_incremental_set(
                    (struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_sorted_settable_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_as_sorted_settable_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_sorted_settable_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_as_sorted_settable_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_sorted_settable_set(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
            + offsetof(struct object, sorted_settable_set_$t$);
    struct butterflyfish_sorted_settable_set_$t$ *out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_$t$_as_sorted_settable_set(
                    (struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_sorted_incremental_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_as_sorted_incremental_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_sorted_incremental_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_as_sorted_incremental_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_sorted_incremental_set(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
            + offsetof(struct object, sorted_incremental_set_$t$);
    struct butterflyfish_sorted_incremental_set_$t$ *out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_$t$_as_sorted_incremental_set(
                    (struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_settable_incremental_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_as_settable_incremental_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_settable_incremental_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_as_settable_incremental_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_settable_incremental_set(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
            + offsetof(struct object, settable_incremental_set_$t$);
    struct butterflyfish_settable_incremental_set_$t$ *out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_$t$_as_settable_incremental_set(
                    (struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_settable_incremental_set_as_settable_set(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
            + offsetof(struct object, settable_set_$t$);
    struct butterflyfish_settable_incremental_set_$t$ *as;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_$t$_as_settable_incremental_set(
            (struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                    &instance, &as), 0);
    struct butterflyfish_settable_set_$t$ *out;
    assert_int_equal(butterflyfish_settable_incremental_set_$t$_as_settable_set(
            as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_sorted_incremental_set_as_sorted_set(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
            + offsetof(struct object, sorted_set_$t$);
    struct butterflyfish_sorted_incremental_set_$t$ *as;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_$t$_as_sorted_incremental_set(
            (struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                    &instance, &as), 0);
    const struct butterflyfish_sorted_set_$t$ *out;
    assert_int_equal(butterflyfish_sorted_incremental_set_$t$_as_sorted_set(
            as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_sorted_incremental_set_as_incremental_set(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
            + offsetof(struct object, incremental_set_$t$);
    struct butterflyfish_sorted_incremental_set_$t$ *as;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_$t$_as_sorted_incremental_set(
            (struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                    &instance, &as), 0);
    struct butterflyfish_incremental_set_$t$ *out;
    assert_int_equal(butterflyfish_sorted_incremental_set_$t$_as_incremental_set(
            as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_incremental_set_as_set(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance + offsetof(struct object, set_$t$);
    struct butterflyfish_incremental_set_$t$ *as;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_$t$_as_incremental_set(
            (struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                    &instance, &as), 0);
    const struct butterflyfish_set_$t$ *out;
    assert_int_equal(butterflyfish_incremental_set_$t$_as_set(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_sorted_set_as_set(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance + offsetof(struct object, set_$t$);
    const struct butterflyfish_sorted_set_$t$ *as;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_$t$_as_sorted_set(
            (const struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                    &instance, &as), 0);
    const struct butterflyfish_set_$t$ *out;
    assert_int_equal(butterflyfish_sorted_set_$t$_as_set(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_addable_as_collection(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
            + offsetof(struct object, collection_$t$);
    struct butterflyfish_addable_$t$ *as;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_$t$_as_addable(
            (struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                    &instance, &as), 0);
    const struct butterflyfish_collection_$t$ *out;
    assert_int_equal(butterflyfish_addable_$t$_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_settable_as_collection(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
            + offsetof(struct object, collection_$t$);
    struct butterflyfish_settable_$t$ *as;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_$t$_as_settable(
            (struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                    &instance, &as), 0);
    const struct butterflyfish_collection_$t$ *out;
    assert_int_equal(butterflyfish_settable_$t$_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_sorted_as_collection(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
            + offsetof(struct object, collection_$t$);
    const struct butterflyfish_sorted_$t$ *as;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_$t$_as_sorted(
            (const struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                    &instance, &as), 0);
    const struct butterflyfish_collection_$t$ *out;
    assert_int_equal(butterflyfish_sorted_$t$_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_count(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_count(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL);
}

static void check_count(void **state) {
    srand(time(NULL));
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(collection_count);
    const uintmax_t check = abs(rand());
    will_return(collection_count, check);
    uintmax_t out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_$t$_count(
            (const struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                    &instance, &out), 0);
    assert_int_equal(out, check);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_first(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_first(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_set_is_empty(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(stream_first);
    will_return(stream_first,
                BUTTERFLYFISH_STREAM_$T$_ERROR_STREAM_IS_EMPTY);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_first(
                    (const struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                            &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_SET_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_last(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_last(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_set_is_empty(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(collection_last);
    will_return(collection_last,
                BUTTERFLYFISH_COLLECTION_$T$_ERROR_COLLECTION_IS_EMPTY);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_last(
                    (const struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                            &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_SET_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_next(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_next(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_next(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL);
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(stream_next);
    will_return(stream_next,
                BUTTERFLYFISH_STREAM_$T$_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_next(
                    (const struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                            &instance, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_prev(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_prev(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_prev(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(collection_prev);
    will_return(collection_prev,
                BUTTERFLYFISH_COLLECTION_$T$_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_prev(
                    (const struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                            &instance, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_END_OF_SEQUENCE);
}

static void check_contains_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_contains(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_contains_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_contains(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL);
}

static void check_contains_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_contains(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL);
}

static void check_contains_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(set_contains);
    will_return(set_contains,
                BUTTERFLYFISH_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_contains(
                    (const struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                            &instance, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_contains_all(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_contains_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_contains_all(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OTHER_IS_NULL);
}

static void check_contains_all_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_contains_all(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL);
}

static void
check_contains_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(set_contains_all);
    will_return(set_contains_all,
                BUTTERFLYFISH_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_contains_all(
                    (const struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                            &instance, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_get(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_get(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_get(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL);
}

static void check_get_error_on_value_not_found(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(set_get);
    will_return(set_get,
                BUTTERFLYFISH_SET_$T$_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_get(
                    (const struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                            &instance, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_NOT_FOUND);
}

static void check_get_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(set_get);
    will_return(set_get,
                BUTTERFLYFISH_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_get(
                    (const struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                            &instance, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_set_item_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_set_item(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_set_item_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_set_item(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_ITEM_IS_NULL);
}

static void check_set_item_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_set_item(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL);
}

static void check_set_item_error_on_value_is_invalid(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(settable_set_item);
    will_return(settable_set_item,
                BUTTERFLYFISH_SETTABLE_$T$_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_set_item(
                    (struct butterflyfish_sorted_settable_incremental_set_$t$
                            *) &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_INVALID);
}

static void check_set_item_error_on_value_already_exists(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(settable_set_item);
    will_return(settable_set_item,
                BUTTERFLYFISH_SETTABLE_$T$_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_set_item(
                    (struct butterflyfish_sorted_settable_incremental_set_$t$
                            *) &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_ALREADY_EXISTS);
}

static void check_set_item_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(settable_set_item);
    will_return(settable_set_item,
                BUTTERFLYFISH_SETTABLE_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_set_item(
                    (struct butterflyfish_sorted_settable_incremental_set_$t$
                            *) &instance, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_set(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_set_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_set(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_ITEM_IS_NULL);
}

static void check_set_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_set(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL);
}

static void check_set_error_on_value_not_found(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(settable_set_set);
    will_return(settable_set_set,
                BUTTERFLYFISH_SETTABLE_SET_$T$_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_set(
                    (struct butterflyfish_sorted_settable_incremental_set_$t$
                            *) &instance, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_NOT_FOUND);
}

static void check_set_error_on_value_is_invalid(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(settable_set_set);
    will_return(settable_set_set,
                BUTTERFLYFISH_SETTABLE_SET_$T$_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_set(
                    (struct butterflyfish_sorted_settable_incremental_set_$t$
                            *) &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_INVALID);
}

static void check_set_error_on_value_already_exists(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(settable_set_set);
    will_return(settable_set_set,
                BUTTERFLYFISH_SETTABLE_SET_$T$_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_set(
                    (struct butterflyfish_sorted_settable_incremental_set_$t$
                            *) &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_ALREADY_EXISTS);
}

static void check_set_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(settable_set_set);
    will_return(settable_set_set,
                BUTTERFLYFISH_SETTABLE_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_set(
                    (struct butterflyfish_sorted_settable_incremental_set_$t$
                            *) &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_add_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_add(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_add_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_add(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL);
}

static void check_add_error_on_value_is_invalid(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(addable_add);
    will_return(addable_add,
                BUTTERFLYFISH_ADDABLE_$T$_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_add(
                    (struct butterflyfish_sorted_settable_incremental_set_$t$
                            *) &instance, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_INVALID);
}

static void check_add_error_on_value_already_exists(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(addable_add);
    will_return(addable_add,
                BUTTERFLYFISH_ADDABLE_$T$_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_add(
                    (struct butterflyfish_sorted_settable_incremental_set_$t$
                            *) &instance, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_ALREADY_EXISTS);
}

static void check_add_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(addable_add);
    will_return(addable_add,
                BUTTERFLYFISH_ADDABLE_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_add(
                    (struct butterflyfish_sorted_settable_incremental_set_$t$
                            *) &instance, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_add_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_add_all(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_add_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_add_all(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OTHER_IS_NULL);
}

static void check_add_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(addable_add_all);
    will_return(addable_add_all,
                BUTTERFLYFISH_ADDABLE_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_add_all(
                    (struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                            &instance, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_ceiling_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_ceiling(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_ceiling_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_ceiling(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL);
}

static void check_ceiling_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_ceiling(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL);
}

static void check_ceiling_error_on_value_not_found(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(sorted_ceiling);
    will_return(sorted_ceiling,
                BUTTERFLYFISH_SORTED_$T$_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_ceiling(
                    (const struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                            &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_NOT_FOUND);
}

static void check_ceiling_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(sorted_ceiling);
    will_return(sorted_ceiling,
                BUTTERFLYFISH_SORTED_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_ceiling(
                    (const struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                            &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_floor_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_floor(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_floor_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_floor(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL);
}

static void check_floor_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_floor(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL);
}

static void check_floor_error_on_value_not_found(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(sorted_floor);
    will_return(sorted_floor,
                BUTTERFLYFISH_SORTED_$T$_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_floor(
                    (const struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                            &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_NOT_FOUND);
}

static void check_floor_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(sorted_floor);
    will_return(sorted_floor,
                BUTTERFLYFISH_SORTED_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_floor(
                    (const struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                            &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_higher_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_higher(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_higher_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_higher(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL);
}

static void check_higher_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_higher(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL);
}

static void check_higher_error_on_value_not_found(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(sorted_higher);
    will_return(sorted_higher,
                BUTTERFLYFISH_SORTED_$T$_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_higher(
                    (const struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                            &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_NOT_FOUND);
}

static void check_higher_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(sorted_higher);
    will_return(sorted_higher,
                BUTTERFLYFISH_SORTED_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_higher(
                    (const struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                            &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_lower_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_lower(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_lower_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_lower(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL);
}

static void check_lower_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_lower(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL);
}

static void check_lower_error_on_value_not_found(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(sorted_lower);
    will_return(sorted_lower,
                BUTTERFLYFISH_SORTED_$T$_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_lower(
                    (const struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                            &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_NOT_FOUND);
}

static void check_lower_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_$t$ =
                    &sorted_settable_incremental_set_$t$,
            .settable_incremental_set_$t$ = &settable_incremental_set_$t$,
            .sorted_incremental_set_$t$ = &sorted_incremental_set_$t$,
            .sorted_settable_set_$t$ = &sorted_settable_set_$t$,
            .incremental_set_$t$ = &incremental_set_$t$,
            .settable_set_$t$ = &settable_set_$t$,
            .sorted_set_$t$ = &sorted_set_$t$,
            .addable_$t$ = &addable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .sorted_$t$ = &sorted_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(sorted_lower);
    will_return(sorted_lower,
                BUTTERFLYFISH_SORTED_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_$t$_lower(
                    (const struct butterflyfish_sorted_settable_incremental_set_$t$ *)
                            &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_as_stream_error_on_object_is_null),
            cmocka_unit_test(check_as_stream_error_on_out_is_null),
            cmocka_unit_test(check_as_stream),
            cmocka_unit_test(check_as_collection_error_on_object_is_null),
            cmocka_unit_test(check_as_collection_error_on_out_is_null),
            cmocka_unit_test(check_as_collection),
            cmocka_unit_test(check_as_sorted_error_on_object_is_null),
            cmocka_unit_test(check_as_sorted_error_on_out_is_null),
            cmocka_unit_test(check_as_sorted),
            cmocka_unit_test(check_as_set_error_on_object_is_null),
            cmocka_unit_test(check_as_set_error_on_out_is_null),
            cmocka_unit_test(check_as_set),
            cmocka_unit_test(check_as_settable_error_on_object_is_null),
            cmocka_unit_test(check_as_settable_error_on_out_is_null),
            cmocka_unit_test(check_as_settable),
            cmocka_unit_test(check_as_addable_error_on_object_is_null),
            cmocka_unit_test(check_as_addable_error_on_out_is_null),
            cmocka_unit_test(check_as_addable),
            cmocka_unit_test(check_as_sorted_set_error_on_object_is_null),
            cmocka_unit_test(check_as_sorted_set_error_on_out_is_null),
            cmocka_unit_test(check_as_sorted_set),
            cmocka_unit_test(check_as_settable_set_error_on_object_is_null),
            cmocka_unit_test(check_as_settable_set_error_on_out_is_null),
            cmocka_unit_test(check_as_settable_set),
            cmocka_unit_test(check_as_incremental_set_error_on_object_is_null),
            cmocka_unit_test(check_as_incremental_set_error_on_out_is_null),
            cmocka_unit_test(check_as_incremental_set),
            cmocka_unit_test(check_as_sorted_settable_set_error_on_object_is_null),
            cmocka_unit_test(check_as_sorted_settable_set_error_on_out_is_null),
            cmocka_unit_test(check_as_sorted_settable_set),
            cmocka_unit_test(check_as_sorted_incremental_set_error_on_object_is_null),
            cmocka_unit_test(check_as_sorted_incremental_set_error_on_out_is_null),
            cmocka_unit_test(check_as_sorted_incremental_set),
            cmocka_unit_test(check_as_settable_incremental_set_error_on_object_is_null),
            cmocka_unit_test(check_as_settable_incremental_set_error_on_out_is_null),
            cmocka_unit_test(check_as_settable_incremental_set),
            cmocka_unit_test(check_settable_incremental_set_as_settable_set),
            cmocka_unit_test(check_sorted_incremental_set_as_sorted_set),
            cmocka_unit_test(check_sorted_incremental_set_as_incremental_set),
            cmocka_unit_test(check_incremental_set_as_set),
            cmocka_unit_test(check_sorted_set_as_set),
            cmocka_unit_test(check_addable_as_collection),
            cmocka_unit_test(check_settable_as_collection),
            cmocka_unit_test(check_sorted_as_collection),
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_count),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_set_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_set_is_empty),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_item_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
            cmocka_unit_test(check_prev_error_on_object_is_null),
            cmocka_unit_test(check_prev_error_on_item_is_null),
            cmocka_unit_test(check_prev_error_on_out_is_null),
            cmocka_unit_test(check_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_contains_error_on_object_is_null),
            cmocka_unit_test(check_contains_error_on_value_is_null),
            cmocka_unit_test(check_contains_error_on_out_is_null),
            cmocka_unit_test(check_contains_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_all_error_on_object_is_null),
            cmocka_unit_test(check_contains_all_error_on_other_is_null),
            cmocka_unit_test(check_contains_all_error_on_out_is_null),
            cmocka_unit_test(check_contains_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_get_error_on_object_is_null),
            cmocka_unit_test(check_get_error_on_value_is_null),
            cmocka_unit_test(check_get_error_on_out_is_null),
            cmocka_unit_test(check_get_error_on_value_not_found),
            cmocka_unit_test(check_get_error_on_memory_allocation_failed),
            cmocka_unit_test(check_set_item_error_on_object_is_null),
            cmocka_unit_test(check_set_item_error_on_item_is_null),
            cmocka_unit_test(check_set_item_error_on_value_is_null),
            cmocka_unit_test(check_set_item_error_on_value_is_invalid),
            cmocka_unit_test(check_set_item_error_on_value_already_exists),
            cmocka_unit_test(check_set_item_error_on_memory_allocation_failed),
            cmocka_unit_test(check_set_error_on_object_is_null),
            cmocka_unit_test(check_set_error_on_item_is_null),
            cmocka_unit_test(check_set_error_on_value_is_null),
            cmocka_unit_test(check_set_error_on_value_not_found),
            cmocka_unit_test(check_set_error_on_value_is_invalid),
            cmocka_unit_test(check_set_error_on_value_already_exists),
            cmocka_unit_test(check_set_error_on_memory_allocation_failed),
            cmocka_unit_test(check_add_error_on_object_is_null),
            cmocka_unit_test(check_add_error_on_value_is_null),
            cmocka_unit_test(check_add_error_on_value_is_invalid),
            cmocka_unit_test(check_add_error_on_value_already_exists),
            cmocka_unit_test(check_add_error_on_memory_allocation_failed),
            cmocka_unit_test(check_add_all_error_on_object_is_null),
            cmocka_unit_test(check_add_all_error_on_other_is_null),
            cmocka_unit_test(check_add_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_ceiling_error_on_object_is_null),
            cmocka_unit_test(check_ceiling_error_on_value_is_null),
            cmocka_unit_test(check_ceiling_error_on_out_is_null),
            cmocka_unit_test(check_ceiling_error_on_value_not_found),
            cmocka_unit_test(check_ceiling_error_on_memory_allocation_failed),
            cmocka_unit_test(check_floor_error_on_object_is_null),
            cmocka_unit_test(check_floor_error_on_value_is_null),
            cmocka_unit_test(check_floor_error_on_out_is_null),
            cmocka_unit_test(check_floor_error_on_value_not_found),
            cmocka_unit_test(check_floor_error_on_memory_allocation_failed),
            cmocka_unit_test(check_higher_error_on_object_is_null),
            cmocka_unit_test(check_higher_error_on_value_is_null),
            cmocka_unit_test(check_higher_error_on_out_is_null),
            cmocka_unit_test(check_higher_error_on_value_not_found),
            cmocka_unit_test(check_higher_error_on_memory_allocation_failed),
            cmocka_unit_test(check_lower_error_on_object_is_null),
            cmocka_unit_test(check_lower_error_on_value_is_null),
            cmocka_unit_test(check_lower_error_on_out_is_null),
            cmocka_unit_test(check_lower_error_on_value_not_found),
            cmocka_unit_test(check_lower_error_on_memory_allocation_failed),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
