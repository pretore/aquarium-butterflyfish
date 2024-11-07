#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

struct object {
    const struct butterflyfish_ordered_reducible_set_i *const
            ordered_reducible_set_i;
    const struct butterflyfish_ordered_set_i *const ordered_set_i;
    const struct butterflyfish_reducible_set_i *const reducible_set_i;
    const struct butterflyfish_removable_i *const removable_i;
    const struct butterflyfish_set_i *const set_i;
    const struct butterflyfish_ordered_i *const ordered_i;
    const struct butterflyfish_collection_i *const collection_i;
    const struct butterflyfish_stream_i *const stream_i;
};

static int stream_first(const struct butterflyfish_stream_i *const object,
                        const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int stream_next(const struct butterflyfish_stream_i *const object,
                       const struct sea_turtle_integer *const item,
                       const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_stream_i stream_i = {
        .first = stream_first,
        .next = stream_next
};

static int as_stream(const struct butterflyfish_collection_i *const object,
                     const struct butterflyfish_stream_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, collection_i, stream_i);
    return 0;
}

static int
collection_last(const struct butterflyfish_collection_i *const object,
                const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int
collection_prev(const struct butterflyfish_collection_i *const object,
                const struct sea_turtle_integer *const item,
                const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

static int
collection_count(const struct butterflyfish_collection_i *const object,
                 uintmax_t *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    *out = mock();
    return 0;
}

const struct butterflyfish_collection_i collection_i = {
        .as_stream = as_stream,
        .last = collection_last,
        .prev = collection_prev,
        .count = collection_count,
};

static int
ordered_as_collection(const struct butterflyfish_ordered_i *const object,
                      const struct butterflyfish_collection_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_i, collection_i);
    return 0;
}

const struct butterflyfish_ordered_i ordered_i = {
        .as_collection = ordered_as_collection,
};

static int
set_as_collection(const struct butterflyfish_set_i *const object,
                  const struct butterflyfish_collection_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, set_i, collection_i);
    return 0;
}

static int
set_contains(const struct butterflyfish_set_i *const object,
             const struct sea_turtle_integer *const value,
             bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static int
set_contains_all(const struct butterflyfish_set_i *const object,
                 const struct butterflyfish_stream_i *const other,
                 bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    assert_non_null(out);
    return mock();
}

static int set_get(const struct butterflyfish_set_i *const object,
                   const struct sea_turtle_integer *const value,
                   const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_set_i set_i = {
        .as_collection = set_as_collection,
        .contains = set_contains,
        .contains_all = set_contains_all,
        .get = set_get,
};

static int
removable_as_collection(
        const struct butterflyfish_removable_i *const object,
        const struct butterflyfish_collection_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, removable_i, collection_i);
    return 0;
}

static int
removable_remove_item(struct butterflyfish_removable_i *const object,
                      const struct sea_turtle_integer *const item) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    return mock();
}

static int
removable_remove_all_items(struct butterflyfish_removable_i *const object,
                           const struct butterflyfish_stream_i *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

const struct butterflyfish_removable_i removable_i = {
        .as_collection = removable_as_collection,
        .remove_item = removable_remove_item,
        .remove_all_items = removable_remove_all_items
};

static int
reducible_set_as_set(const struct butterflyfish_reducible_set_i *const object,
                     const struct butterflyfish_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, reducible_set_i, set_i);
    return 0;
}

static int
reducible_set_as_removable(struct butterflyfish_reducible_set_i *const object,
                           struct butterflyfish_removable_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, reducible_set_i,
            removable_i);
    return 0;
}

static int
reducible_set_remove(struct butterflyfish_reducible_set_i *const object,
                     const struct sea_turtle_integer *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    return mock();
}

static int
reducible_set_remove_all(struct butterflyfish_reducible_set_i *const object,
                         const struct butterflyfish_stream_i *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static int
reducible_set_retain_all(struct butterflyfish_reducible_set_i *const object,
                         const struct butterflyfish_stream_i *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

const struct butterflyfish_reducible_set_i reducible_set_i = {
        .as_set = reducible_set_as_set,
        .as_removable = reducible_set_as_removable,
        .remove = reducible_set_remove,
        .remove_all = reducible_set_remove_all,
        .retain_all = reducible_set_retain_all,
};

static int
ordered_set_as_set(const struct butterflyfish_ordered_set_i *const object,
                   const struct butterflyfish_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_set_i, set_i);
    return 0;
}

static int
ordered_set_as_ordered(const struct butterflyfish_ordered_set_i *const object,
                       const struct butterflyfish_ordered_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_set_i, ordered_i);
    return 0;
}

const struct butterflyfish_ordered_set_i ordered_set_i = {
        .as_ordered = ordered_set_as_ordered,
        .as_set = ordered_set_as_set,
};

static int ordered_reducible_set_as_ordered_set(
        const struct butterflyfish_ordered_reducible_set_i *const object,
        const struct butterflyfish_ordered_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_reducible_set_i,
            ordered_set_i);
    return 0;
}

static int
ordered_reducible_set_as_reducible_set(
        struct butterflyfish_ordered_reducible_set_i *const object,
        struct butterflyfish_reducible_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_reducible_set_i,
                              reducible_set_i);
    return 0;
}

const struct butterflyfish_ordered_reducible_set_i ordered_reducible_set_i = {
        .as_ordered_set = ordered_reducible_set_as_ordered_set,
        .as_reducible_set = ordered_reducible_set_as_reducible_set,
};

static void check_as_stream_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_as_stream(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_stream_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_as_stream((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_stream(void **state) {
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance + offsetof(struct object, stream_i);
    const struct butterflyfish_stream_i *out;
    assert_int_equal(butterflyfish_ordered_reducible_set_i_as_stream(
            (const struct butterflyfish_ordered_reducible_set_i *) &instance,
                    &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_collection_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_as_collection(
                    NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_collection_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_as_collection(
                    (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_collection(void **state) {
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check =
            (char *) &instance + offsetof(struct object, collection_i);
    const struct butterflyfish_collection_i *out;
    assert_int_equal(butterflyfish_ordered_reducible_set_i_as_collection(
            (const struct butterflyfish_ordered_reducible_set_i *) &instance,
                    &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_ordered_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_as_ordered(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_ordered_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_as_ordered((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_ordered(void **state) {
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance + offsetof(struct object, ordered_i);
    const struct butterflyfish_ordered_i *out;
    assert_int_equal(butterflyfish_ordered_reducible_set_i_as_ordered(
            (struct butterflyfish_ordered_reducible_set_i *) &instance, &out),
                    0);
    assert_ptr_equal(out, check);
}

static void check_as_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_as_set(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_as_set((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_set(void **state) {
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance + offsetof(struct object, set_i);
    const struct butterflyfish_set_i *out;
    assert_int_equal(butterflyfish_ordered_reducible_set_i_as_set(
            (struct butterflyfish_ordered_reducible_set_i *) &instance, &out),
                    0);
    assert_ptr_equal(out, check);
}

static void check_as_removable_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_as_removable(
                    NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_removable_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_as_removable(
                    (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_removable(void **state) {
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, removable_i);
    struct butterflyfish_removable_i *out;
    assert_int_equal(butterflyfish_ordered_reducible_set_i_as_removable(
            (struct butterflyfish_ordered_reducible_set_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_reducible_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_as_reducible_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_reducible_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_as_reducible_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_reducible_set(void **state) {
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, reducible_set_i);
    struct butterflyfish_reducible_set_i *out;
    assert_int_equal(butterflyfish_ordered_reducible_set_i_as_reducible_set(
            (struct butterflyfish_ordered_reducible_set_i *) &instance, &out),
                     0);
    assert_ptr_equal(out, check);
}

static void check_as_ordered_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_as_ordered_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_ordered_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_as_ordered_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_ordered_set(void **state) {
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, ordered_set_i);
    const struct butterflyfish_ordered_set_i *out;
    assert_int_equal(butterflyfish_ordered_reducible_set_i_as_ordered_set(
            (struct butterflyfish_ordered_reducible_set_i *) &instance, &out),
                     0);
    assert_ptr_equal(out, check);
}

static void check_reducible_set_as_set(void **state) {
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance + offsetof(struct object, set_i);
    struct butterflyfish_reducible_set_i *as;
    assert_int_equal(butterflyfish_ordered_reducible_set_i_as_reducible_set(
            (struct butterflyfish_ordered_reducible_set_i *) &instance, &as),
                     0);
    const struct butterflyfish_set_i *out;
    assert_int_equal(butterflyfish_reducible_set_i_as_set(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_ordered_set_as_set(void **state) {
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance + offsetof(struct object, set_i);
    const struct butterflyfish_ordered_set_i *as;
    assert_int_equal(butterflyfish_ordered_reducible_set_i_as_ordered_set(
            (struct butterflyfish_ordered_reducible_set_i *) &instance, &as),
                     0);
    const struct butterflyfish_set_i *out;
    assert_int_equal(butterflyfish_ordered_set_i_as_set(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_removable_as_collection(void **state) {
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, collection_i);
    struct butterflyfish_removable_i *as;
    assert_int_equal(butterflyfish_ordered_reducible_set_i_as_removable(
            (struct butterflyfish_ordered_reducible_set_i *) &instance,
            &as), 0);
    const struct butterflyfish_collection_i *out;
    assert_int_equal(butterflyfish_removable_i_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_ordered_as_collection(void **state) {
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, collection_i);
    const struct butterflyfish_ordered_i *as;
    assert_int_equal(butterflyfish_ordered_reducible_set_i_as_ordered(
            (struct butterflyfish_ordered_reducible_set_i *) &instance,
                    &as), 0);
    const struct butterflyfish_collection_i *out;
    assert_int_equal(butterflyfish_ordered_i_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_count(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_count((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_count(void **state) {
    srand(time(NULL));
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(collection_count);
    const uintmax_t check = abs(rand());
    will_return(collection_count, check);
    uintmax_t out;
    assert_int_equal(butterflyfish_ordered_reducible_set_i_count(
            (const struct butterflyfish_ordered_reducible_set_i *) &instance,
                    &out), 0);
    assert_int_equal(out, check);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_first(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_first((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_set_is_empty(void **state) {
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(stream_first);
    will_return(stream_first,
                BUTTERFLYFISH_STREAM_I_ERROR_STREAM_IS_EMPTY);
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_first(
                    (const struct butterflyfish_ordered_reducible_set_i *)
                            &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_SET_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_last(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_last((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_set_is_empty(void **state) {
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(collection_last);
    will_return(collection_last,
                BUTTERFLYFISH_COLLECTION_I_ERROR_COLLECTION_IS_EMPTY);
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_last(
                    (const struct butterflyfish_ordered_reducible_set_i *)
                            &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_SET_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_next(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_next(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_next(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(stream_next);
    will_return(stream_next,
                BUTTERFLYFISH_STREAM_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_next(
                    (const struct butterflyfish_ordered_reducible_set_i *)
                            &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_prev(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_prev(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_prev(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(collection_prev);
    will_return(collection_prev,
                BUTTERFLYFISH_COLLECTION_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_prev(
                    (const struct butterflyfish_ordered_reducible_set_i *)
                            &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_END_OF_SEQUENCE);
}

static void check_contains_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_contains(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_contains_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_contains(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_contains_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_contains(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_contains_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(set_contains);
    will_return(set_contains,
                BUTTERFLYFISH_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_contains(
                    (struct butterflyfish_ordered_reducible_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_contains_all(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_contains_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_contains_all(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OTHER_IS_NULL);
}

static void check_contains_all_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_contains_all(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OUT_IS_NULL);
}

static void
check_contains_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(set_contains_all);
    will_return(set_contains_all,
                BUTTERFLYFISH_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_contains_all(
                    (struct butterflyfish_ordered_reducible_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_get(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_get(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_get(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_get_error_on_value_not_found(void **state) {
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(set_get);
    will_return(set_get,
                BUTTERFLYFISH_SET_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_get(
                    (struct butterflyfish_ordered_reducible_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_VALUE_NOT_FOUND);
}

static void check_get_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(set_get);
    will_return(set_get,
                BUTTERFLYFISH_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_get(
                    (struct butterflyfish_ordered_reducible_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_item_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_remove_item(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_item_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_remove_item((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_ITEM_IS_NULL);
}

static void check_remove_item(void **state) {
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(removable_remove_item);
    will_return(removable_remove_item, 0);
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_remove_item(
                    (struct butterflyfish_ordered_reducible_set_i *) &instance,
                    (void *) 1), 0);
}

static void check_remove_all_items_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_remove_all_items(
                    NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_items_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_remove_all_items(
                    (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OTHER_IS_NULL);
}

static void check_remove_all_items(void **state) {
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(removable_remove_all_items);
    will_return(removable_remove_all_items, 0);
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_remove_all_items(
                    (struct butterflyfish_ordered_reducible_set_i *) &instance,
                    (void *) 1), 0);
}

static void check_remove_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_remove(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_remove((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_remove_error_on_value_not_found(void **state) {
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(reducible_set_remove);
    will_return(reducible_set_remove,
                BUTTERFLYFISH_REDUCIBLE_SET_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_remove(
                    (struct butterflyfish_ordered_reducible_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_VALUE_NOT_FOUND);
}

static void check_remove_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(reducible_set_remove);
    will_return(reducible_set_remove,
                BUTTERFLYFISH_REDUCIBLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_remove(
                    (struct butterflyfish_ordered_reducible_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_remove_all(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_remove_all((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OTHER_IS_NULL);
}

static void check_remove_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(reducible_set_remove_all);
    will_return(reducible_set_remove_all,
                BUTTERFLYFISH_REDUCIBLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_remove_all(
                    (struct butterflyfish_ordered_reducible_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_retain_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_retain_all(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_retain_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_retain_all((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_OTHER_IS_NULL);
}

static void
check_retain_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_set_i = &ordered_set_i,
            .reducible_set_i = &reducible_set_i,
            .removable_i = &removable_i,
            .set_i = &set_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(reducible_set_retain_all);
    will_return(reducible_set_retain_all,
                BUTTERFLYFISH_REDUCIBLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_retain_all(
                    (struct butterflyfish_ordered_reducible_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_REDUCIBLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_as_stream_error_on_object_is_null),
            cmocka_unit_test(check_as_stream_error_on_out_is_null),
            cmocka_unit_test(check_as_stream),
            cmocka_unit_test(check_as_collection_error_on_object_is_null),
            cmocka_unit_test(check_as_collection_error_on_out_is_null),
            cmocka_unit_test(check_as_collection),
            cmocka_unit_test(check_as_ordered_error_on_object_is_null),
            cmocka_unit_test(check_as_ordered_error_on_out_is_null),
            cmocka_unit_test(check_as_ordered),
            cmocka_unit_test(check_as_set_error_on_object_is_null),
            cmocka_unit_test(check_as_set_error_on_out_is_null),
            cmocka_unit_test(check_as_set),
            cmocka_unit_test(check_as_removable_error_on_object_is_null),
            cmocka_unit_test(check_as_removable_error_on_out_is_null),
            cmocka_unit_test(check_as_removable),
            cmocka_unit_test(check_as_reducible_set_error_on_object_is_null),
            cmocka_unit_test(check_as_reducible_set_error_on_out_is_null),
            cmocka_unit_test(check_as_reducible_set),
            cmocka_unit_test(check_ordered_set_as_set),
            cmocka_unit_test(check_as_ordered_set_error_on_object_is_null),
            cmocka_unit_test(check_as_ordered_set_error_on_out_is_null),
            cmocka_unit_test(check_as_ordered_set),
            cmocka_unit_test(check_reducible_set_as_set),
            cmocka_unit_test(check_removable_as_collection),
            cmocka_unit_test(check_ordered_as_collection),
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
