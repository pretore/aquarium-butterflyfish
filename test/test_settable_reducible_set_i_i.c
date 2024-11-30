#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>
#include <test/cmocka.h>

struct object {
    const struct butterflyfish_settable_reducible_set_i_i
            *const settable_reducible_set_i_i;
    const struct butterflyfish_reducible_set_i_i *const reducible_set_i_i;
    const struct butterflyfish_settable_set_i_i *const settable_set_i_i;
    const struct butterflyfish_settable_i_i *const settable_i_i;
    const struct butterflyfish_removable_i_i *const removable_i_i;
    const struct butterflyfish_set_i_i *const set_i_i;
    const struct butterflyfish_collection_i_i *const collection_i_i;
    const struct butterflyfish_stream_i_i *const stream_i_i;
};

static int stream_first(const struct butterflyfish_stream_i_i *const object,
                        const struct butterflyfish_map_i_i_entry **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int stream_next(const struct butterflyfish_stream_i_i *const object,
                       const struct butterflyfish_map_i_i_entry *const item,
                       const struct butterflyfish_map_i_i_entry **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_stream_i_i stream_i_i = {
        .first = stream_first,
        .next = stream_next
};

static int as_stream(const struct butterflyfish_collection_i_i *const object,
                     const struct butterflyfish_stream_i_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, collection_i_i, stream_i_i);
    return 0;
}

static int
collection_last(const struct butterflyfish_collection_i_i *const object,
                const struct butterflyfish_map_i_i_entry **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int
collection_prev(const struct butterflyfish_collection_i_i *const object,
                const struct butterflyfish_map_i_i_entry *const item,
                const struct butterflyfish_map_i_i_entry **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

static int
collection_count(const struct butterflyfish_collection_i_i *const object,
                 uintmax_t *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    *out = mock();
    return 0;
}

const struct butterflyfish_collection_i_i collection_i_i = {
        .as_stream = as_stream,
        .last = collection_last,
        .prev = collection_prev,
        .count = collection_count,
};

static int
settable_as_collection(const struct butterflyfish_settable_i_i *const object,
                       const struct butterflyfish_collection_i_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, settable_i_i, collection_i_i);
    return 0;
}

static int
settable_set_item(struct butterflyfish_settable_i_i *const object,
                  const struct butterflyfish_map_i_i_entry *const item,
                  const struct butterflyfish_map_i_i_entry *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(value);
    return mock();
}

const struct butterflyfish_settable_i_i settable_i_i = {
        .as_collection = settable_as_collection,
        .set_item = settable_set_item,
};

static int
set_as_collection(const struct butterflyfish_set_i_i *const object,
                  const struct butterflyfish_collection_i_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, set_i_i, collection_i_i);
    return 0;
}

static int set_contains(const struct butterflyfish_set_i_i *const object,
                        const struct butterflyfish_map_i_i_entry *const value,
                        bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static int set_contains_all(const struct butterflyfish_set_i_i *const object,
                            const struct butterflyfish_stream_i_i *const other,
                            bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    assert_non_null(out);
    return mock();
}

static int set_get(const struct butterflyfish_set_i_i *const object,
                   const struct butterflyfish_map_i_i_entry *const value,
                   const struct butterflyfish_map_i_i_entry **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_set_i_i set_i_i = {
        .as_collection = set_as_collection,
        .contains = set_contains,
        .contains_all = set_contains_all,
        .get = set_get,
};

static int
removable_as_collection(
        const struct butterflyfish_removable_i_i *const object,
        const struct butterflyfish_collection_i_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, removable_i_i,
            collection_i_i);
    return 0;
}

static int
removable_remove_item(struct butterflyfish_removable_i_i *const object,
                      const struct butterflyfish_map_i_i_entry *const item) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    return mock();
}

static int
removable_remove_all_items(struct butterflyfish_removable_i_i *const object,
                           const struct butterflyfish_stream_i_i *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

const struct butterflyfish_removable_i_i removable_i_i = {
        .as_collection = removable_as_collection,
        .remove_item = removable_remove_item,
        .remove_all_items = removable_remove_all_items,
};

static int
settable_set_as_set(const struct butterflyfish_settable_set_i_i *const object,
                    const struct butterflyfish_set_i_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, settable_set_i_i, set_i_i);
    return 0;
}

static int
settable_set_as_settable(struct butterflyfish_settable_set_i_i *const object,
                         struct butterflyfish_settable_i_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, settable_set_i_i,
                              settable_i_i);
    return 0;
}

static int
settable_set_set(struct butterflyfish_settable_set_i_i *const object,
                 const struct butterflyfish_map_i_i_entry *const item,
                 const struct butterflyfish_map_i_i_entry *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(value);
    return mock();
}

const struct butterflyfish_settable_set_i_i settable_set_i_i = {
        .as_settable = settable_set_as_settable,
        .as_set = settable_set_as_set,
        .set = settable_set_set,
};

static int
reducible_set_as_set(const struct butterflyfish_reducible_set_i_i *const object,
                     const struct butterflyfish_set_i_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, reducible_set_i_i, set_i_i);
    return 0;
}

static int
reducible_set_as_removable(struct butterflyfish_reducible_set_i_i *const object,
                           struct butterflyfish_removable_i_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, reducible_set_i_i,
                              removable_i_i);
    return 0;
}

static int
reducible_set_remove(struct butterflyfish_reducible_set_i_i *const object,
                     const struct butterflyfish_map_i_i_entry *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    return mock();
}

static int
reducible_set_remove_all(struct butterflyfish_reducible_set_i_i *const object,
                         const struct butterflyfish_stream_i_i *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static int
reducible_set_retain_all(struct butterflyfish_reducible_set_i_i *const object,
                         const struct butterflyfish_stream_i_i *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

const struct butterflyfish_reducible_set_i_i reducible_set_i_i = {
        .as_set = reducible_set_as_set,
        .as_removable = reducible_set_as_removable,
        .remove = reducible_set_remove,
        .remove_all = reducible_set_remove_all,
        .retain_all = reducible_set_retain_all,
};

static int
settable_reducible_set_as_settable_set(
        struct butterflyfish_settable_reducible_set_i_i *const object,
        struct butterflyfish_settable_set_i_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, settable_reducible_set_i_i,
                              settable_set_i_i);
    return 0;
}

static int
settable_reducible_set_as_reducible_set(
        struct butterflyfish_settable_reducible_set_i_i *const object,
        struct butterflyfish_reducible_set_i_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, settable_reducible_set_i_i,
                              reducible_set_i_i);
    return 0;
}

const struct
butterflyfish_settable_reducible_set_i_i settable_reducible_set_i_i = {
        .as_settable_set = settable_reducible_set_as_settable_set,
        .as_reducible_set = settable_reducible_set_as_reducible_set,
};

static void check_as_stream_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_as_stream(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_stream_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_as_stream(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL);
}

static void check_as_stream(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    const void *check = (char *) &instance + offsetof(struct object, stream_i_i);
    const struct butterflyfish_stream_i_i *out;
    assert_int_equal(butterflyfish_settable_reducible_set_i_i_as_stream(
            (const struct butterflyfish_settable_reducible_set_i_i *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_collection_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_as_collection(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_collection_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_as_collection(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL);
}

static void check_as_collection(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, collection_i_i);
    const struct butterflyfish_collection_i_i *out;
    assert_int_equal(butterflyfish_settable_reducible_set_i_i_as_collection(
            (const struct butterflyfish_settable_reducible_set_i_i *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_settable_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_as_settable(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_settable_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_as_settable(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL);
}

static void check_as_settable(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, settable_i_i);
    struct butterflyfish_settable_i_i *out;
    assert_int_equal(butterflyfish_settable_reducible_set_i_i_as_settable(
            (struct butterflyfish_settable_reducible_set_i_i *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_as_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_as_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL);
}

static void check_as_set(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    const void *check = (char *) &instance + offsetof(struct object, set_i_i);
    const struct butterflyfish_set_i_i *out;
    assert_int_equal(butterflyfish_settable_reducible_set_i_i_as_set(
            (const struct butterflyfish_settable_reducible_set_i_i *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_removable_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_as_removable(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_removable_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_as_removable(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL);
}

static void check_as_removable(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, removable_i_i);
    struct butterflyfish_removable_i_i *out;
    assert_int_equal(butterflyfish_settable_reducible_set_i_i_as_removable(
            (struct butterflyfish_settable_reducible_set_i_i *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_settable_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_as_settable_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_settable_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_as_settable_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL);
}

static void check_as_settable_set(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, settable_set_i_i);
    struct butterflyfish_settable_set_i_i *out;
    assert_int_equal(butterflyfish_settable_reducible_set_i_i_as_settable_set(
            (struct butterflyfish_settable_reducible_set_i_i *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_reducible_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_as_reducible_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_reducible_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_as_reducible_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL);
}

static void check_as_reducible_set(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, reducible_set_i_i);
    struct butterflyfish_reducible_set_i_i *out;
    assert_int_equal(butterflyfish_settable_reducible_set_i_i_as_reducible_set(
            (struct butterflyfish_settable_reducible_set_i_i *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_reducible_set_as_set(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    const void *check = (char *) &instance + offsetof(struct object, set_i_i);
    struct butterflyfish_reducible_set_i_i *as;
    assert_int_equal(butterflyfish_settable_reducible_set_i_i_as_reducible_set(
            (struct butterflyfish_settable_reducible_set_i_i *)
                    &instance, &as), 0);
    const struct butterflyfish_set_i_i *out;
    assert_int_equal(butterflyfish_reducible_set_i_i_as_set(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_removable_as_collection(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, collection_i_i);
    struct butterflyfish_removable_i_i *as;
    assert_int_equal(butterflyfish_settable_reducible_set_i_i_as_removable(
            (struct butterflyfish_settable_reducible_set_i_i *)
                    &instance, &as), 0);
    const struct butterflyfish_collection_i_i *out;
    assert_int_equal(butterflyfish_removable_i_i_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_settable_as_collection(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, collection_i_i);
    struct butterflyfish_settable_i_i *as;
    assert_int_equal(butterflyfish_settable_reducible_set_i_i_as_settable(
            (struct butterflyfish_settable_reducible_set_i_i *)
                    &instance, &as), 0);
    const struct butterflyfish_collection_i_i *out;
    assert_int_equal(butterflyfish_settable_i_i_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_count(NULL, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_count((void *) 1, NULL),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL);
}

static void check_count(void **state) {
    srand(time(NULL));
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(collection_count);
    const uintmax_t check = abs(rand());
    will_return(collection_count, check);
    uintmax_t out;
    assert_int_equal(butterflyfish_settable_reducible_set_i_i_count(
            (const struct butterflyfish_settable_reducible_set_i_i *)
                    &instance, &out), 0);
    assert_int_equal(out, check);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_first(NULL, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_first((void *) 1, NULL),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_set_is_empty(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(stream_first);
    will_return(stream_first,
                BUTTERFLYFISH_STREAM_I_I_ERROR_STREAM_IS_EMPTY);
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_first(
                    (const struct butterflyfish_settable_reducible_set_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_SET_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_last(NULL, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_last((void *) 1, NULL),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_set_is_empty(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(collection_last);
    will_return(collection_last,
                BUTTERFLYFISH_COLLECTION_I_I_ERROR_COLLECTION_IS_EMPTY);
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_last(
                    (const struct butterflyfish_settable_reducible_set_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_SET_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_next(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_next(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_next(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL);
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(stream_next);
    will_return(stream_next,
                BUTTERFLYFISH_STREAM_I_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_next(
                    (const struct butterflyfish_settable_reducible_set_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_prev(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_prev(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_prev(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(collection_prev);
    will_return(collection_prev,
                BUTTERFLYFISH_COLLECTION_I_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_prev(
                    (const struct butterflyfish_settable_reducible_set_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_END_OF_SEQUENCE);
}

static void check_contains_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_contains(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_contains_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_contains(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_VALUE_IS_NULL);
}

static void check_contains_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_contains(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL);
}

static void check_contains_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(set_contains);
    will_return(set_contains,
                BUTTERFLYFISH_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_contains(
                    (const struct butterflyfish_settable_reducible_set_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_contains_all(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_contains_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_contains_all(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OTHER_IS_NULL);
}

static void check_contains_all_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_contains_all(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL);
}

static void
check_contains_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(set_contains_all);
    will_return(set_contains_all,
                BUTTERFLYFISH_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_contains_all(
                    (const struct butterflyfish_settable_reducible_set_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_get(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_get(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_VALUE_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_get(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL);
}

static void check_get_error_on_value_not_found(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(set_get);
    will_return(set_get,
                BUTTERFLYFISH_SET_I_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_get(
                    (const struct butterflyfish_settable_reducible_set_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_VALUE_NOT_FOUND);
}

static void check_get_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(set_get);
    will_return(set_get,
                BUTTERFLYFISH_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_get(
                    (const struct butterflyfish_settable_reducible_set_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_set_item_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_set_item(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_set_item_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_set_item(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_ITEM_IS_NULL);
}

static void check_set_item_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_set_item(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_VALUE_IS_NULL);
}

static void check_set_item_error_on_value_is_invalid(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(settable_set_item);
    will_return(settable_set_item,
                BUTTERFLYFISH_SETTABLE_I_I_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_set_item(
                    (struct butterflyfish_settable_reducible_set_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_VALUE_IS_INVALID);
}

static void check_set_item_error_on_value_already_exists(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(settable_set_item);
    will_return(settable_set_item,
                BUTTERFLYFISH_SETTABLE_I_I_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_set_item(
                    (struct butterflyfish_settable_reducible_set_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_VALUE_ALREADY_EXISTS);
}

static void check_set_item_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(settable_set_item);
    will_return(settable_set_item,
                BUTTERFLYFISH_SETTABLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_set_item(
                    (struct butterflyfish_settable_reducible_set_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_set(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_set_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_set(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_ITEM_IS_NULL);
}

static void check_set_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_set(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_VALUE_IS_NULL);
}

static void check_set_error_on_value_not_found(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(settable_set_set);
    will_return(settable_set_set,
                BUTTERFLYFISH_SETTABLE_SET_I_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_set(
                    (struct butterflyfish_settable_reducible_set_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_VALUE_NOT_FOUND);
}

static void check_set_error_on_value_is_invalid(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(settable_set_set);
    will_return(settable_set_set,
                BUTTERFLYFISH_SETTABLE_SET_I_I_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_set(
                    (struct butterflyfish_settable_reducible_set_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_VALUE_IS_INVALID);
}

static void check_set_error_on_value_already_exists(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(settable_set_set);
    will_return(settable_set_set,
                BUTTERFLYFISH_SETTABLE_SET_I_I_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_set(
                    (struct butterflyfish_settable_reducible_set_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_VALUE_ALREADY_EXISTS);
}

static void check_set_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(settable_set_set);
    will_return(settable_set_set,
                BUTTERFLYFISH_SETTABLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_set(
                    (struct butterflyfish_settable_reducible_set_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_item_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_remove_item(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_item_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_remove_item(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_ITEM_IS_NULL);
}

static void check_remove_item(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(removable_remove_item);
    will_return(removable_remove_item, 0);
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_remove_item(
                    (struct butterflyfish_settable_reducible_set_i_i *) &instance,
                    (void *) 1), 0);
}

static void check_remove_all_items_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_remove_all_items(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_items_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_remove_all_items(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OTHER_IS_NULL);
}

static void check_remove_all_items(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(removable_remove_all_items);
    will_return(removable_remove_all_items, 0);
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_remove_all_items(
                    (struct butterflyfish_settable_reducible_set_i_i *) &instance,
                    (void *) 1), 0);
}

static void check_remove_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_remove(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_remove(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_VALUE_IS_NULL);
}

static void check_remove_error_on_value_not_found(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(reducible_set_remove);
    will_return(reducible_set_remove,
                BUTTERFLYFISH_REDUCIBLE_SET_I_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_remove(
                    (struct butterflyfish_settable_reducible_set_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_VALUE_NOT_FOUND);
}

static void check_remove_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(reducible_set_remove);
    will_return(reducible_set_remove,
                BUTTERFLYFISH_REDUCIBLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_remove(
                    (struct butterflyfish_settable_reducible_set_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_remove_all(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_remove_all(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OTHER_IS_NULL);
}

static void check_remove_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(reducible_set_remove_all);
    will_return(reducible_set_remove_all,
                BUTTERFLYFISH_REDUCIBLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_remove_all(
                    (struct butterflyfish_settable_reducible_set_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_retain_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_retain_all(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_retain_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_retain_all(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_OTHER_IS_NULL);
}

static void
check_retain_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .settable_reducible_set_i_i = &settable_reducible_set_i_i,
            .reducible_set_i_i = &reducible_set_i_i,
            .settable_set_i_i = &settable_set_i_i,
            .settable_i_i = &settable_i_i,
            .removable_i_i = &removable_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(reducible_set_retain_all);
    will_return(reducible_set_retain_all,
                BUTTERFLYFISH_REDUCIBLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_settable_reducible_set_i_i_retain_all(
                    (struct butterflyfish_settable_reducible_set_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_as_stream_error_on_object_is_null),
            cmocka_unit_test(check_as_stream_error_on_out_is_null),
            cmocka_unit_test(check_as_stream),
            cmocka_unit_test(check_as_collection_error_on_object_is_null),
            cmocka_unit_test(check_as_collection_error_on_out_is_null),
            cmocka_unit_test(check_as_collection),
            cmocka_unit_test(check_as_settable_error_on_object_is_null),
            cmocka_unit_test(check_as_settable_error_on_out_is_null),
            cmocka_unit_test(check_as_settable),
            cmocka_unit_test(check_as_set_error_on_object_is_null),
            cmocka_unit_test(check_as_set_error_on_out_is_null),
            cmocka_unit_test(check_as_set),
            cmocka_unit_test(check_as_removable_error_on_object_is_null),
            cmocka_unit_test(check_as_removable_error_on_out_is_null),
            cmocka_unit_test(check_as_removable),
            cmocka_unit_test(check_as_settable_set_error_on_object_is_null),
            cmocka_unit_test(check_as_settable_set_error_on_out_is_null),
            cmocka_unit_test(check_as_settable_set),
            cmocka_unit_test(check_as_reducible_set_error_on_object_is_null),
            cmocka_unit_test(check_as_reducible_set_error_on_out_is_null),
            cmocka_unit_test(check_as_reducible_set),
            cmocka_unit_test(check_reducible_set_as_set),
            cmocka_unit_test(check_removable_as_collection),
            cmocka_unit_test(check_settable_as_collection),
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
            cmocka_unit_test(check_remove_item_error_on_object_is_null),
            cmocka_unit_test(check_remove_item_error_on_item_is_null),
            cmocka_unit_test(check_remove_item),
            cmocka_unit_test(check_remove_all_items_error_on_object_is_null),
            cmocka_unit_test(check_remove_all_items_error_on_item_is_null),
            cmocka_unit_test(check_remove_all_items),
            cmocka_unit_test(check_remove_error_on_object_is_null),
            cmocka_unit_test(check_remove_error_on_value_is_null),
            cmocka_unit_test(check_remove_error_on_value_not_found),
            cmocka_unit_test(check_remove_error_on_memory_allocation_failed),
            cmocka_unit_test(check_remove_all_error_on_object_is_null),
            cmocka_unit_test(check_remove_all_error_on_other_is_null),
            cmocka_unit_test(check_remove_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_retain_all_error_on_object_is_null),
            cmocka_unit_test(check_retain_all_error_on_other_is_null),
            cmocka_unit_test(check_retain_all_error_on_memory_allocation_failed),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
