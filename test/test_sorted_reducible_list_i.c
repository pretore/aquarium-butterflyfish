#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>
#include <test/cmocka.h>

struct object {
    const struct butterflyfish_sorted_reducible_list_i *const
            sorted_reducible_list_i;
    const struct butterflyfish_sorted_list_i *const sorted_list_i;
    const struct butterflyfish_reducible_list_i *const reducible_list_i;
    const struct butterflyfish_removable_i *const removable_i;
    const struct butterflyfish_sorted_i *const sorted_i;
    const struct butterflyfish_list_i *const list_i;
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
list_as_collection(const struct butterflyfish_list_i *const object,
                   const struct butterflyfish_collection_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, list_i, collection_i);
    return 0;
}

static int list_get(const struct butterflyfish_list_i *const object,
                    const uintmax_t at,
                    const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int list_at(const struct butterflyfish_list_i *const object,
                   const struct sea_turtle_integer *const item,
                   uintmax_t *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_list_i list_i = {
        .as_collection = list_as_collection,
        .get = list_get,
        .at = list_at
};

static int
sorted_as_collection(const struct butterflyfish_sorted_i *const object,
                     const struct butterflyfish_collection_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, sorted_i, collection_i);
    return 0;
}

static int
sorted_ceiling(const struct butterflyfish_sorted_i *const object,
               const struct sea_turtle_integer *const value,
               const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static int
sorted_floor(const struct butterflyfish_sorted_i *const object,
             const struct sea_turtle_integer *const value,
             const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static int
sorted_higher(const struct butterflyfish_sorted_i *const object,
              const struct sea_turtle_integer *const value,
              const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static int
sorted_lower(const struct butterflyfish_sorted_i *const object,
             const struct sea_turtle_integer *const value,
             const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_sorted_i sorted_i = {
        .as_collection = sorted_as_collection,
        .ceiling = sorted_ceiling,
        .floor = sorted_floor,
        .higher = sorted_higher,
        .lower = sorted_lower,
};

static int
removable_as_collection(const struct butterflyfish_removable_i *const object,
                        const struct butterflyfish_collection_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, removable_i,
            collection_i);
    return 0;
}

static int
removable_remove_item(struct butterflyfish_removable_i *const object,
                      const struct sea_turtle_integer *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static int
removable_remove_all_items(
        struct butterflyfish_removable_i *const object,
        const struct butterflyfish_stream_i *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

const struct butterflyfish_removable_i removable_i = {
        .as_collection = removable_as_collection,
        .remove_item = removable_remove_item,
        .remove_all_items = removable_remove_all_items,
};

static int
reducible_list_as_list(
        const struct butterflyfish_reducible_list_i *const object,
        const struct butterflyfish_list_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, reducible_list_i, list_i);
    return 0;
}

static int
reducible_list_as_removable(struct butterflyfish_reducible_list_i *const object,
                            struct butterflyfish_removable_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, reducible_list_i,
                              removable_i);
    return 0;
}

static int
reducible_list_remove(struct butterflyfish_reducible_list_i *const object,
                      const uintmax_t at) {
    function_called();
    assert_non_null(object);
    return mock();
}

static int
reducible_list_remove_all(struct butterflyfish_reducible_list_i *const object,
                          const struct butterflyfish_stream_ni *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

const struct butterflyfish_reducible_list_i reducible_list_i = {
        .as_list = reducible_list_as_list,
        .as_removable = reducible_list_as_removable,
        .remove = reducible_list_remove,
        .remove_all = reducible_list_remove_all,
};

static int
sorted_list_as_sorted(const struct butterflyfish_sorted_list_i *const object,
                      const struct butterflyfish_sorted_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, sorted_list_i, sorted_i);
    return 0;
}

static int
sorted_list_as_list(const struct butterflyfish_sorted_list_i *const object,
                    const struct butterflyfish_list_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, sorted_list_i, list_i);
    return 0;
}

const struct butterflyfish_sorted_list_i sorted_list_i = {
        .as_sorted = sorted_list_as_sorted,
        .as_list = sorted_list_as_list,
};

static int
sorted_reducible_list_as_reducible_list(
        struct butterflyfish_sorted_reducible_list_i *const object,
        struct butterflyfish_reducible_list_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, sorted_reducible_list_i,
            reducible_list_i);
    return 0;
}

static int
sorted_reducible_list_as_sorted_list(
        const struct butterflyfish_sorted_reducible_list_i *const object,
        const struct butterflyfish_sorted_list_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, sorted_reducible_list_i,
                              sorted_list_i);
    return 0;
}

const struct butterflyfish_sorted_reducible_list_i sorted_reducible_list_i = {
        .as_reducible_list = sorted_reducible_list_as_reducible_list,
        .as_sorted_list = sorted_reducible_list_as_sorted_list,
};

static void check_as_stream_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_as_stream(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_stream_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_as_stream((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_as_stream(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance + offsetof(struct object, stream_i);
    const struct butterflyfish_stream_i *out;
    assert_int_equal(butterflyfish_sorted_reducible_list_i_as_stream(
            (const struct butterflyfish_sorted_reducible_list_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_collection_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_as_collection(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_collection_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_as_collection((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_as_collection(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, collection_i);
    const struct butterflyfish_collection_i *out;
    assert_int_equal(butterflyfish_sorted_reducible_list_i_as_collection(
            (const struct butterflyfish_sorted_reducible_list_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_list_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_as_list(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_list_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_as_list((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_as_list(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance + offsetof(struct object, list_i);
    const struct butterflyfish_list_i *out;
    assert_int_equal(butterflyfish_sorted_reducible_list_i_as_list(
            (const struct butterflyfish_sorted_reducible_list_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_sorted_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_as_sorted(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_sorted_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_as_sorted((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_as_sorted(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance + offsetof(struct object, sorted_i);
    const struct butterflyfish_sorted_i *out;
    assert_int_equal(butterflyfish_sorted_reducible_list_i_as_sorted(
            (const struct butterflyfish_sorted_reducible_list_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_removable_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_as_removable(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_removable_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_as_removable((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_as_removable(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, removable_i);
    struct butterflyfish_removable_i *out;
    assert_int_equal(butterflyfish_sorted_reducible_list_i_as_removable(
            (struct butterflyfish_sorted_reducible_list_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_sorted_list_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_as_sorted_list(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_sorted_list_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_as_sorted_list(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_as_sorted_list(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, sorted_list_i);
    const struct butterflyfish_sorted_list_i *out;
    assert_int_equal(butterflyfish_sorted_reducible_list_i_as_sorted_list(
            (const struct butterflyfish_sorted_reducible_list_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_reducible_list_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_as_reducible_list(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_reducible_list_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_as_reducible_list(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_as_reducible_list(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, reducible_list_i);
    struct butterflyfish_reducible_list_i *out;
    assert_int_equal(butterflyfish_sorted_reducible_list_i_as_reducible_list(
            (struct butterflyfish_sorted_reducible_list_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void check_list_as_collection(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, collection_i);
    const struct butterflyfish_list_i *as;
    assert_int_equal(butterflyfish_sorted_reducible_list_i_as_list(
            (const struct butterflyfish_sorted_reducible_list_i *) &instance,
            &as), 0);
    const struct butterflyfish_collection_i *out;
    assert_int_equal(butterflyfish_list_i_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_sorted_as_collection(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, collection_i);
    const struct butterflyfish_sorted_i *as;
    assert_int_equal(butterflyfish_sorted_reducible_list_i_as_sorted(
            (const struct butterflyfish_sorted_reducible_list_i *) &instance,
            &as), 0);
    const struct butterflyfish_collection_i *out;
    assert_int_equal(butterflyfish_sorted_i_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_removable_as_collection(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, collection_i);
    struct butterflyfish_removable_i *as;
    assert_int_equal(butterflyfish_sorted_reducible_list_i_as_removable(
            (struct butterflyfish_sorted_reducible_list_i *) &instance,
            &as), 0);
    const struct butterflyfish_collection_i *out;
    assert_int_equal(butterflyfish_removable_i_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_reducible_list_as_list(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance + offsetof(struct object, list_i);
    struct butterflyfish_reducible_list_i *as;
    assert_int_equal(butterflyfish_sorted_reducible_list_i_as_reducible_list(
            (struct butterflyfish_sorted_reducible_list_i *) &instance,
            &as), 0);
    const struct butterflyfish_list_i *out;
    assert_int_equal(butterflyfish_reducible_list_i_as_list(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_count(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_count((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_count(void **state) {
    srand(time(NULL));
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(collection_count);
    const uintmax_t check = abs(rand());
    will_return(collection_count, check);
    uintmax_t out;
    assert_int_equal(butterflyfish_sorted_reducible_list_i_count(
            (const struct butterflyfish_sorted_reducible_list_i *) &instance,
            &out), 0);
    assert_int_equal(out, check);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_first(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_first((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_list_is_empty(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(stream_first);
    will_return(stream_first,
                BUTTERFLYFISH_STREAM_I_ERROR_STREAM_IS_EMPTY);
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_first(
                    (const struct butterflyfish_sorted_reducible_list_i *)
                            &instance,
                    (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_LIST_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_last(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_last((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_list_is_empty(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(collection_last);
    will_return(collection_last,
                BUTTERFLYFISH_COLLECTION_I_ERROR_COLLECTION_IS_EMPTY);
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_last(
                    (const struct butterflyfish_sorted_reducible_list_i *)
                            &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_LIST_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(stream_next);
    will_return(stream_next,
                BUTTERFLYFISH_STREAM_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_next(
                    (const struct butterflyfish_sorted_reducible_list_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(collection_prev);
    will_return(collection_prev,
                BUTTERFLYFISH_COLLECTION_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_prev(
                    (const struct butterflyfish_sorted_reducible_list_i *)
                            &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_END_OF_SEQUENCE);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_get(NULL, 0, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_get((void *) 1, 0, NULL),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_get_error_on_index_out_of_bounds(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(list_get);
    will_return(list_get,
                BUTTERFLYFISH_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_get(
                    (const struct butterflyfish_sorted_reducible_list_i *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS);
}

static void check_at_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_at(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_at_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_at((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_ITEM_IS_NULL);
}

static void check_at_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_at((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_at_error_on_item_not_found(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(list_at);
    will_return(list_at,
                BUTTERFLYFISH_LIST_I_ERROR_ITEM_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_at(
                    (const struct butterflyfish_sorted_reducible_list_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_ITEM_NOT_FOUND);
}

static void check_remove_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_remove(NULL, 0),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(reducible_list_remove);
    will_return(reducible_list_remove, 0);
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_remove(
                    (struct butterflyfish_sorted_reducible_list_i *) &instance, 0),
            0);
}

static void check_remove_error_on_index_out_of_bounds(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(reducible_list_remove);
    will_return(reducible_list_remove,
                BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_remove(
                    (struct butterflyfish_sorted_reducible_list_i *) &instance,
                    0),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS);
}

static void check_remove_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_remove_all(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_remove_all((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OTHER_IS_NULL);
}

static void check_remove_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(reducible_list_remove_all);
    will_return(reducible_list_remove_all,
                BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_remove_all(
                    (struct butterflyfish_sorted_reducible_list_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_item_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_remove_item(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_item_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_remove_item((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_ITEM_IS_NULL);
}

static void check_remove_item(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(removable_remove_item);
    will_return(removable_remove_item, 0);
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_remove_item(
                    (struct butterflyfish_sorted_reducible_list_i *) &instance,
                    (void *) 1),
            0);
}

static void check_remove_all_items_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_remove_all_items(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_items_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_remove_all_items((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OTHER_IS_NULL);
}

static void check_remove_all_items(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(removable_remove_all_items);
    will_return(removable_remove_all_items, 0);
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_remove_all_items(
                    (struct butterflyfish_sorted_reducible_list_i *) &instance,
                    (void *) 1),
            0);
}

static void check_ceiling_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_ceiling(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_ceiling_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_ceiling(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_VALUE_IS_NULL);
}

static void check_ceiling_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_ceiling(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_ceiling_error_on_value_not_found(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(sorted_ceiling);
    will_return(sorted_ceiling,
                BUTTERFLYFISH_SORTED_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_ceiling(
                    (const struct butterflyfish_sorted_reducible_list_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_VALUE_NOT_FOUND);
}

static void check_ceiling_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(sorted_ceiling);
    will_return(sorted_ceiling,
                BUTTERFLYFISH_SORTED_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_ceiling(
                    (const struct butterflyfish_sorted_reducible_list_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_floor_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_floor(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_floor_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_floor(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_VALUE_IS_NULL);
}

static void check_floor_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_floor(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_floor_error_on_value_not_found(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(sorted_floor);
    will_return(sorted_floor,
                BUTTERFLYFISH_SORTED_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_floor(
                    (const struct butterflyfish_sorted_reducible_list_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_VALUE_NOT_FOUND);
}

static void check_floor_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(sorted_floor);
    will_return(sorted_floor,
                BUTTERFLYFISH_SORTED_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_floor(
                    (const struct butterflyfish_sorted_reducible_list_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_higher_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_higher(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_higher_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_higher(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_VALUE_IS_NULL);
}

static void check_higher_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_higher(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_higher_error_on_value_not_found(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(sorted_higher);
    will_return(sorted_higher,
                BUTTERFLYFISH_SORTED_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_higher(
                    (const struct butterflyfish_sorted_reducible_list_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_VALUE_NOT_FOUND);
}

static void check_higher_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(sorted_higher);
    will_return(sorted_higher,
                BUTTERFLYFISH_SORTED_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_higher(
                    (const struct butterflyfish_sorted_reducible_list_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_lower_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_lower(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_lower_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_lower(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_VALUE_IS_NULL);
}

static void check_lower_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_lower(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_lower_error_on_value_not_found(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(sorted_lower);
    will_return(sorted_lower,
                BUTTERFLYFISH_SORTED_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_lower(
                    (const struct butterflyfish_sorted_reducible_list_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_VALUE_NOT_FOUND);
}

static void check_lower_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_reducible_list_i = &sorted_reducible_list_i,
            .sorted_list_i = &sorted_list_i,
            .reducible_list_i = &reducible_list_i,
            .removable_i = &removable_i,
            .sorted_i = &sorted_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(sorted_lower);
    will_return(sorted_lower,
                BUTTERFLYFISH_SORTED_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_reducible_list_i_lower(
                    (const struct butterflyfish_sorted_reducible_list_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_REDUCIBLE_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_as_stream_error_on_object_is_null),
            cmocka_unit_test(check_as_stream_error_on_out_is_null),
            cmocka_unit_test(check_as_stream),
            cmocka_unit_test(check_as_collection_error_on_object_is_null),
            cmocka_unit_test(check_as_collection_error_on_out_is_null),
            cmocka_unit_test(check_as_collection),
            cmocka_unit_test(check_as_list_error_on_object_is_null),
            cmocka_unit_test(check_as_list_error_on_out_is_null),
            cmocka_unit_test(check_as_list),
            cmocka_unit_test(check_as_sorted_error_on_object_is_null),
            cmocka_unit_test(check_as_sorted_error_on_out_is_null),
            cmocka_unit_test(check_as_sorted),
            cmocka_unit_test(check_as_removable_error_on_object_is_null),
            cmocka_unit_test(check_as_removable_error_on_out_is_null),
            cmocka_unit_test(check_as_removable),
            cmocka_unit_test(check_as_sorted_list_error_on_object_is_null),
            cmocka_unit_test(check_as_sorted_list_error_on_out_is_null),
            cmocka_unit_test(check_as_sorted_list),
            cmocka_unit_test(check_as_reducible_list_error_on_object_is_null),
            cmocka_unit_test(check_as_reducible_list_error_on_out_is_null),
            cmocka_unit_test(check_as_reducible_list),
            cmocka_unit_test(check_removable_as_collection),
            cmocka_unit_test(check_list_as_collection),
            cmocka_unit_test(check_sorted_as_collection),
            cmocka_unit_test(check_reducible_list_as_list),
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_count),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_list_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_list_is_empty),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_item_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
            cmocka_unit_test(check_prev_error_on_object_is_null),
            cmocka_unit_test(check_prev_error_on_item_is_null),
            cmocka_unit_test(check_prev_error_on_out_is_null),
            cmocka_unit_test(check_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_get_error_on_object_is_null),
            cmocka_unit_test(check_get_error_on_out_is_null),
            cmocka_unit_test(check_get_error_on_index_out_of_bounds),
            cmocka_unit_test(check_at_error_on_object_is_null),
            cmocka_unit_test(check_at_error_on_item_is_null),
            cmocka_unit_test(check_at_error_on_out_is_null),
            cmocka_unit_test(check_at_error_on_item_not_found),
            cmocka_unit_test(check_remove_error_on_object_is_null),
            cmocka_unit_test(check_remove),
            cmocka_unit_test(check_remove_error_on_index_out_of_bounds),
            cmocka_unit_test(check_remove_all_error_on_object_is_null),
            cmocka_unit_test(check_remove_all_error_on_other_is_null),
            cmocka_unit_test(check_remove_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_remove_item_error_on_object_is_null),
            cmocka_unit_test(check_remove_item),
            cmocka_unit_test(check_remove_item_error_on_item_is_null),
            cmocka_unit_test(check_remove_all_items_error_on_object_is_null),
            cmocka_unit_test(check_remove_all_items),
            cmocka_unit_test(check_remove_all_items_error_on_other_is_null),
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
