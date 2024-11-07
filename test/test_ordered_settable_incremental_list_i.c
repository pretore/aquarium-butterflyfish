#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

struct object {
    const struct butterflyfish_ordered_settable_incremental_list_i *const
            ordered_settable_incremental_list_i;
    const struct butterflyfish_settable_incremental_list_i *const
            settable_incremental_list_i;
    const struct butterflyfish_ordered_settable_list_i *const
            ordered_settable_list_i;
    const struct butterflyfish_ordered_incremental_list_i *const
            ordered_incremental_list_i;
    const struct butterflyfish_settable_list_i *const settable_list_i;
    const struct butterflyfish_incremental_list_i *const incremental_list_i;
    const struct butterflyfish_ordered_list_i *const ordered_list_i;
    const struct butterflyfish_insertable_i *const insertable_i;
    const struct butterflyfish_settable_i *const settable_i;
    const struct butterflyfish_addable_i *const addable_i;
    const struct butterflyfish_list_i *const list_i;
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
settable_as_collection(const struct butterflyfish_settable_i *const object,
                       const struct butterflyfish_collection_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, settable_i, collection_i);
    return 0;
}

static int
settable_set_item(struct butterflyfish_settable_i *const object,
                  const struct sea_turtle_integer *const item,
                  const struct sea_turtle_integer *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(value);
    return mock();
}

const struct butterflyfish_settable_i settable_i = {
        .as_collection = settable_as_collection,
        .set_item = settable_set_item
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
insertable_as_ordered(const struct butterflyfish_insertable_i *const object,
                      const struct butterflyfish_ordered_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, insertable_i, ordered_i);
    return 0;
}

static int
insertable_insert(struct butterflyfish_insertable_i *const object,
                  const struct sea_turtle_integer *const item,
                  const struct sea_turtle_integer *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(value);
    return mock();
}

static int
insertable_insert_all(struct butterflyfish_insertable_i *const object,
                      const struct sea_turtle_integer *const item,
                      const struct butterflyfish_stream_i *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(other);
    return mock();
}

const struct butterflyfish_insertable_i insertable_i = {
        .as_ordered = insertable_as_ordered,
        .insert = insertable_insert,
        .insert_all = insertable_insert_all,
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
ordered_list_as_list(const struct butterflyfish_ordered_list_i *const object,
                     const struct butterflyfish_list_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_list_i, list_i);
    return 0;
}

static int
ordered_list_as_ordered(
        const struct butterflyfish_ordered_list_i *const object,
        const struct butterflyfish_ordered_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_list_i,
                              ordered_i);
    return 0;
}

const struct butterflyfish_ordered_list_i ordered_list_i = {
        .as_list = ordered_list_as_list,
        .as_ordered = ordered_list_as_ordered
};

static int
settable_list_as_settable(struct butterflyfish_settable_list_i *const object,
                          struct butterflyfish_settable_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            settable_list_i,
            settable_i);
    return 0;
}

static int
settable_list_as_list(const struct butterflyfish_settable_list_i *const object,
                      const struct butterflyfish_list_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, settable_list_i, list_i);
    return 0;
}

static int
settable_list_set(struct butterflyfish_settable_list_i *const object,
               const uintmax_t at,
               const struct sea_turtle_integer *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    return mock();
}

const struct butterflyfish_settable_list_i settable_list_i = {
        .as_settable = settable_list_as_settable,
        .as_list = settable_list_as_list,
        .set = settable_list_set,
};

static int
ordered_settable_list_as_settable_list(
        struct butterflyfish_ordered_settable_list_i *const object,
        struct butterflyfish_settable_list_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_settable_list_i,
            settable_list_i);
    return 0;
}

static int
ordered_settable_list_as_ordered_list(
        const struct butterflyfish_ordered_settable_list_i *const object,
        const struct butterflyfish_ordered_list_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_settable_list_i,
                              ordered_list_i);
    return 0;
}

const struct butterflyfish_ordered_settable_list_i ordered_settable_list_i = {
        .as_settable_list = ordered_settable_list_as_settable_list,
        .as_ordered_list = ordered_settable_list_as_ordered_list,
};

static int
addable_as_collection(const struct butterflyfish_addable_i *const object,
                      const struct butterflyfish_collection_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, addable_i, collection_i);
    return 0;
}

static int
addable_add(struct butterflyfish_addable_i *const object,
            const struct sea_turtle_integer *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    return mock();
}

static int
addable_add_all(struct butterflyfish_addable_i *const object,
                const struct butterflyfish_stream_i *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

const struct butterflyfish_addable_i addable_i = {
        .as_collection = addable_as_collection,
        .add = addable_add,
        .add_all = addable_add_all
};

static int
incremental_list_as_list(
        const struct butterflyfish_incremental_list_i *const object,
        const struct butterflyfish_list_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, incremental_list_i,
                              list_i);
    return 0;
}

static int
incremental_list_as_addable(
        struct butterflyfish_incremental_list_i *const object,
        struct butterflyfish_addable_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, incremental_list_i,
                              addable_i);
    return 0;
}

const struct butterflyfish_incremental_list_i incremental_list_i = {
        .as_addable = incremental_list_as_addable,
        .as_list = incremental_list_as_list,
};

static int
settable_incremental_list_as_incremental_list(
        struct butterflyfish_settable_incremental_list_i *const object,
        struct butterflyfish_incremental_list_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              settable_incremental_list_i, incremental_list_i);
    return 0;
}

static int
settable_incremental_list_as_settable_list(
        struct butterflyfish_settable_incremental_list_i *const object,
        struct butterflyfish_settable_list_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              settable_incremental_list_i, settable_list_i);
    return 0;
}

const struct
butterflyfish_settable_incremental_list_i settable_incremental_list_i = {
        .as_incremental_list = settable_incremental_list_as_incremental_list,
        .as_settable_list = settable_incremental_list_as_settable_list,
};

static int
ordered_incremental_list_as_ordered_list(
        const struct butterflyfish_ordered_incremental_list_i *const object,
        const struct butterflyfish_ordered_list_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            ordered_incremental_list_i, ordered_list_i);
    return 0;
}

static int
ordered_incremental_list_as_insertable(
        struct butterflyfish_ordered_incremental_list_i *const object,
        struct butterflyfish_insertable_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              ordered_incremental_list_i, insertable_i);
    return 0;
}

static int
ordered_incremental_list_as_incremental_list(
        struct butterflyfish_ordered_incremental_list_i *const object,
        struct butterflyfish_incremental_list_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              ordered_incremental_list_i, incremental_list_i);
    return 0;
}

const struct
butterflyfish_ordered_incremental_list_i ordered_incremental_list_i = {
        .as_ordered_list = ordered_incremental_list_as_ordered_list,
        .as_insertable = ordered_incremental_list_as_insertable,
        .as_incremental_list = ordered_incremental_list_as_incremental_list,
};

static int
ordered_settable_incremental_list_as_settable_incremental_list(
        struct butterflyfish_ordered_settable_incremental_list_i *const object,
        struct butterflyfish_settable_incremental_list_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              ordered_settable_incremental_list_i,
                              settable_incremental_list_i);
    return 0;
}

static int
ordered_settable_incremental_list_as_ordered_settable_list(
        struct butterflyfish_ordered_settable_incremental_list_i *const object,
        struct butterflyfish_ordered_settable_list_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              ordered_settable_incremental_list_i,
                              ordered_settable_list_i);
    return 0;
}

static int
ordered_settable_incremental_list_as_ordered_incremental_list(
        struct butterflyfish_ordered_settable_incremental_list_i *const object,
        struct butterflyfish_ordered_incremental_list_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              ordered_settable_incremental_list_i,
                              ordered_incremental_list_i);
    return 0;
}

const struct
butterflyfish_ordered_settable_incremental_list_i
ordered_settable_incremental_list_i = {
        .as_settable_incremental_list =
                ordered_settable_incremental_list_as_settable_incremental_list,
        .as_ordered_settable_list =
                ordered_settable_incremental_list_as_ordered_settable_list,
        .as_ordered_incremental_list =
                ordered_settable_incremental_list_as_ordered_incremental_list,
};

static void check_as_stream_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_stream(
                    NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_stream_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_stream(
                    (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_as_stream(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance + offsetof(struct object, stream_i);
    const struct butterflyfish_stream_i *out;
    assert_int_equal(butterflyfish_ordered_settable_incremental_list_i_as_stream(
            (const struct butterflyfish_ordered_settable_incremental_list_i
                    *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_collection_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_collection(
                    NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_collection_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_collection(
                    (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_as_collection(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, collection_i);
    const struct butterflyfish_collection_i *out;
    assert_int_equal(butterflyfish_ordered_settable_incremental_list_i_as_collection(
            (const struct butterflyfish_ordered_settable_incremental_list_i
                    *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_ordered_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_ordered(
                    NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_ordered_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_ordered(
                    (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_as_ordered(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, ordered_i);
    const struct butterflyfish_ordered_i *out;
    assert_int_equal(butterflyfish_ordered_settable_incremental_list_i_as_ordered(
            (const struct butterflyfish_ordered_settable_incremental_list_i
            *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_list_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_list(
                    NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_list_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_list(
                    (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_as_list(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, list_i);
    const struct butterflyfish_list_i *out;
    assert_int_equal(butterflyfish_ordered_settable_incremental_list_i_as_list(
            (const struct butterflyfish_ordered_settable_incremental_list_i
                    *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_addable_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_addable(
                    NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_addable_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_addable(
                    (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_as_addable(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, addable_i);
    struct butterflyfish_addable_i *out;
    assert_int_equal(butterflyfish_ordered_settable_incremental_list_i_as_addable(
            (struct butterflyfish_ordered_settable_incremental_list_i *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_settable_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_settable(
                    NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_settable_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_settable(
                    (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_as_settable(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, settable_i);
    struct butterflyfish_settable_i *out;
    assert_int_equal(butterflyfish_ordered_settable_incremental_list_i_as_settable(
            (struct butterflyfish_ordered_settable_incremental_list_i
            *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_insertable_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_insertable(
                    NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_insertable_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_insertable(
                    (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_as_insertable(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, insertable_i);
    struct butterflyfish_insertable_i *out;
    assert_int_equal(butterflyfish_ordered_settable_incremental_list_i_as_insertable(
            (struct butterflyfish_ordered_settable_incremental_list_i
            *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_ordered_list_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_ordered_list(
                    NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_ordered_list_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_ordered_list(
                    (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_as_ordered_list(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, ordered_list_i);
    const struct butterflyfish_ordered_list_i *out;
    assert_int_equal(butterflyfish_ordered_settable_incremental_list_i_as_ordered_list(
            (const struct butterflyfish_ordered_settable_incremental_list_i
            *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_incremental_list_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_incremental_list(
                    NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_incremental_list_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_incremental_list(
                    (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_as_incremental_list(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, incremental_list_i);
    struct butterflyfish_incremental_list_i *out;
    assert_int_equal(butterflyfish_ordered_settable_incremental_list_i_as_incremental_list(
            (struct butterflyfish_ordered_settable_incremental_list_i *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_settable_list_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_settable_list(
                    NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_settable_list_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_settable_list(
                    (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_as_settable_list(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, settable_list_i);
    struct butterflyfish_settable_list_i *out;
    assert_int_equal(butterflyfish_ordered_settable_incremental_list_i_as_settable_list(
            (struct butterflyfish_ordered_settable_incremental_list_i *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_ordered_incremental_list_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_ordered_incremental_list(
                    NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_ordered_incremental_list_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_ordered_incremental_list(
                    (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_as_ordered_incremental_list(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, ordered_incremental_list_i);
    struct butterflyfish_ordered_incremental_list_i *out;
    assert_int_equal(butterflyfish_ordered_settable_incremental_list_i_as_ordered_incremental_list(
            (struct butterflyfish_ordered_settable_incremental_list_i *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_ordered_settable_list_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_ordered_settable_list(
                    NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_ordered_settable_list_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_ordered_settable_list(
                    (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_as_ordered_settable_list(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, ordered_settable_list_i);
    struct butterflyfish_ordered_settable_list_i *out;
    assert_int_equal(butterflyfish_ordered_settable_incremental_list_i_as_ordered_settable_list(
            (struct butterflyfish_ordered_settable_incremental_list_i *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_settable_incremental_list_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_settable_incremental_list(
                    NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_settable_incremental_list_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_as_settable_incremental_list(
                    (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_as_settable_incremental_list(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, settable_incremental_list_i);
    struct butterflyfish_settable_incremental_list_i *out;
    assert_int_equal(butterflyfish_ordered_settable_incremental_list_i_as_settable_incremental_list(
            (struct butterflyfish_ordered_settable_incremental_list_i *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_settable_incremental_list_as_settable_list(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, settable_list_i);
    struct butterflyfish_settable_incremental_list_i *as;
    assert_int_equal(butterflyfish_ordered_settable_incremental_list_i_as_settable_incremental_list(
            (struct butterflyfish_ordered_settable_incremental_list_i *) &instance,
            &as), 0);
    struct butterflyfish_settable_list_i *out;
    assert_int_equal(butterflyfish_settable_incremental_list_i_as_settable_list(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_settable_incremental_list_as_incremental_list(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, incremental_list_i);
    struct butterflyfish_settable_incremental_list_i *as;
    assert_int_equal(butterflyfish_ordered_settable_incremental_list_i_as_settable_incremental_list(
            (struct butterflyfish_ordered_settable_incremental_list_i *) &instance,
            &as), 0);
    struct butterflyfish_incremental_list_i *out;
    assert_int_equal(butterflyfish_settable_incremental_list_i_as_incremental_list(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_incremental_list_as_list(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance + offsetof(struct object, list_i);
    struct butterflyfish_incremental_list_i *as;
    assert_int_equal(butterflyfish_ordered_settable_incremental_list_i_as_incremental_list(
            (struct butterflyfish_ordered_settable_incremental_list_i *) &instance,
            &as), 0);
    const struct butterflyfish_list_i *out;
    assert_int_equal(butterflyfish_incremental_list_i_as_list(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_addable_as_collection(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, collection_i);
    struct butterflyfish_addable_i *as;
    assert_int_equal(butterflyfish_ordered_settable_incremental_list_i_as_addable(
            (struct butterflyfish_ordered_settable_incremental_list_i *) &instance,
            &as), 0);
    const struct butterflyfish_collection_i *out;
    assert_int_equal(butterflyfish_addable_i_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_ordered_settable_list_as_ordered_list(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, ordered_list_i);
    struct butterflyfish_ordered_settable_list_i *as;
    assert_int_equal(butterflyfish_ordered_settable_incremental_list_i_as_ordered_settable_list(
            (struct butterflyfish_ordered_settable_incremental_list_i *) &instance,
            &as), 0);
    const struct butterflyfish_ordered_list_i *out;
    assert_int_equal(butterflyfish_ordered_settable_list_i_as_ordered_list(
            as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_settable_list_as_list(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance + offsetof(struct object, list_i);
    struct butterflyfish_settable_list_i *as;
    assert_int_equal(butterflyfish_ordered_settable_incremental_list_i_as_settable_list(
            (struct butterflyfish_ordered_settable_incremental_list_i *) &instance,
            &as), 0);
    const struct butterflyfish_list_i *out;
    assert_int_equal(butterflyfish_settable_list_i_as_list(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_insertable_as_ordered(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, ordered_i);
    struct butterflyfish_insertable_i *as;
    assert_int_equal(butterflyfish_ordered_settable_incremental_list_i_as_insertable(
            (struct butterflyfish_ordered_settable_incremental_list_i *) &instance,
            &as), 0);
    const struct butterflyfish_ordered_i *out;
    assert_int_equal(butterflyfish_insertable_i_as_ordered(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_ordered_as_collection(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, collection_i);
    const struct butterflyfish_ordered_i *as;
    assert_int_equal(butterflyfish_ordered_settable_incremental_list_i_as_ordered(
            (struct butterflyfish_ordered_settable_incremental_list_i *) &instance,
            &as), 0);
    const struct butterflyfish_collection_i *out;
    assert_int_equal(butterflyfish_ordered_i_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_settable_as_collection(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, collection_i);
    struct butterflyfish_settable_i *as;
    assert_int_equal(butterflyfish_ordered_settable_incremental_list_i_as_settable(
            (struct butterflyfish_ordered_settable_incremental_list_i *) &instance,
            &as), 0);
    const struct butterflyfish_collection_i *out;
    assert_int_equal(butterflyfish_settable_i_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_count(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_count((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_count(void **state) {
    srand(time(NULL));
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(collection_count);
    const uintmax_t check = abs(rand());
    will_return(collection_count, check);
    uintmax_t out;
    assert_int_equal(butterflyfish_ordered_settable_incremental_list_i_count(
            (const struct butterflyfish_ordered_settable_incremental_list_i *) &instance, &out), 0);
    assert_int_equal(out, check);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_first(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_first((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_list_is_empty(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(stream_first);
    will_return(stream_first,
                BUTTERFLYFISH_STREAM_I_ERROR_STREAM_IS_EMPTY);
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_first(
                    (const struct butterflyfish_ordered_settable_incremental_list_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_LIST_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_last(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_last((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_list_is_empty(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(collection_last);
    will_return(collection_last,
                BUTTERFLYFISH_COLLECTION_I_ERROR_COLLECTION_IS_EMPTY);
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_last(
                    (const struct butterflyfish_ordered_settable_incremental_list_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_LIST_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(stream_next);
    will_return(stream_next,
                BUTTERFLYFISH_STREAM_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_next(
                    (const struct butterflyfish_ordered_settable_incremental_list_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(collection_prev);
    will_return(collection_prev,
                BUTTERFLYFISH_COLLECTION_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_prev(
                    (const struct butterflyfish_ordered_settable_incremental_list_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_END_OF_SEQUENCE);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_get(NULL, 0, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_get((void *) 1, 0, NULL),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_get_error_on_index_out_of_bounds(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(list_get);
    will_return(list_get,
                BUTTERFLYFISH_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_get(
                    (const struct butterflyfish_ordered_settable_incremental_list_i *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS);
}

static void check_at_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_at(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_at_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_at((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_ITEM_IS_NULL);
}

static void check_at_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_at((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_at_error_on_item_not_found(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(list_at);
    will_return(list_at,
                BUTTERFLYFISH_LIST_I_ERROR_ITEM_NOT_FOUND);
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_at(
                    (const struct butterflyfish_ordered_settable_incremental_list_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_ITEM_NOT_FOUND);
}

static void check_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_set(NULL, 0, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_set_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_set((void *) 1, 0, NULL),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_VALUE_IS_NULL);
}

static void check_set_error_on_index_out_of_bounds(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(settable_list_set);
    will_return(settable_list_set,
                BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_set(
                    (struct butterflyfish_ordered_settable_incremental_list_i *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS);
}

static void check_set_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(settable_list_set);
    will_return(settable_list_set,
                BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_set(
                    (struct butterflyfish_ordered_settable_incremental_list_i *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_set_error_on_value_is_invalid(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(settable_list_set);
    will_return(settable_list_set,
                BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_set(
                    (struct butterflyfish_ordered_settable_incremental_list_i *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_VALUE_IS_INVALID);
}

static void check_set_item_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_set_item(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_set_item_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_set_item(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_ITEM_IS_NULL);
}

static void check_set_item_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_set_item(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_VALUE_IS_NULL);
}

static void check_set_item_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(settable_set_item);
    will_return(settable_set_item,
                BUTTERFLYFISH_SETTABLE_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_set_item(
                    (struct butterflyfish_ordered_settable_incremental_list_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_set_item_error_on_value_is_invalid(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(settable_set_item);
    will_return(settable_set_item,
                BUTTERFLYFISH_SETTABLE_I_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_set_item(
                    (struct butterflyfish_ordered_settable_incremental_list_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_VALUE_IS_INVALID);
}

static void check_add_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_add(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_add_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_add((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_VALUE_IS_NULL);
}

static void check_add_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(addable_add);
    will_return(addable_add,
                BUTTERFLYFISH_ADDABLE_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_add(
                    (struct butterflyfish_ordered_settable_incremental_list_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_add_error_on_value_is_invalid(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(addable_add);
    will_return(addable_add,
                BUTTERFLYFISH_ADDABLE_I_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_add(
                    (struct butterflyfish_ordered_settable_incremental_list_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_VALUE_IS_INVALID);
}

static void check_add_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_add_all(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_add_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_add_all((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_OTHER_IS_NULL);
}

static void check_add_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(addable_add_all);
    will_return(addable_add_all,
                BUTTERFLYFISH_ADDABLE_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_add_all(
                    (struct butterflyfish_ordered_settable_incremental_list_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_insert_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_insert(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_insert_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_insert(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_ITEM_IS_NULL);
}

static void check_insert_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_insert(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_VALUE_IS_NULL);
}

static void check_insert_error_on_value_is_invalid(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(insertable_insert);
    will_return(insertable_insert,
                BUTTERFLYFISH_INSERTABLE_I_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_insert(
                    (struct butterflyfish_ordered_settable_incremental_list_i *)
                            &instance, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_VALUE_IS_INVALID);
}

static void check_insert_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(insertable_insert);
    will_return(insertable_insert,
                BUTTERFLYFISH_INSERTABLE_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_insert(
                    (struct butterflyfish_ordered_settable_incremental_list_i *)
                            &instance, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_insert_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_insert_all(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_insert_all_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_insert_all(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_ITEM_IS_NULL);
}

static void check_insert_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_insert_all(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OTHER_IS_NULL);
}

static void check_insert_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_settable_incremental_list_i =
                    &ordered_settable_incremental_list_i,
            .settable_incremental_list_i = &settable_incremental_list_i,
            .ordered_settable_list_i = &ordered_settable_list_i,
            .ordered_incremental_list_i = &ordered_incremental_list_i,
            .settable_list_i = &settable_list_i,
            .incremental_list_i = &incremental_list_i,
            .ordered_list_i = &ordered_list_i,
            .insertable_i = &insertable_i,
            .settable_i = &settable_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(insertable_insert_all);
    will_return(insertable_insert_all,
                BUTTERFLYFISH_INSERTABLE_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_list_i_insert_all(
                    (struct butterflyfish_ordered_settable_incremental_list_i *)
                            &instance, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED);
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
            cmocka_unit_test(check_as_list_error_on_object_is_null),
            cmocka_unit_test(check_as_list_error_on_out_is_null),
            cmocka_unit_test(check_as_list),
            cmocka_unit_test(check_as_addable_error_on_object_is_null),
            cmocka_unit_test(check_as_addable_error_on_out_is_null),
            cmocka_unit_test(check_as_addable),
            cmocka_unit_test(check_as_settable_error_on_object_is_null),
            cmocka_unit_test(check_as_settable_error_on_out_is_null),
            cmocka_unit_test(check_as_settable),
            cmocka_unit_test(check_as_insertable_error_on_object_is_null),
            cmocka_unit_test(check_as_insertable_error_on_out_is_null),
            cmocka_unit_test(check_as_insertable),
            cmocka_unit_test(check_as_ordered_list_error_on_object_is_null),
            cmocka_unit_test(check_as_ordered_list_error_on_out_is_null),
            cmocka_unit_test(check_as_ordered_list),
            cmocka_unit_test(check_as_incremental_list_error_on_object_is_null),
            cmocka_unit_test(check_as_incremental_list_error_on_out_is_null),
            cmocka_unit_test(check_as_incremental_list),
            cmocka_unit_test(check_as_settable_list_error_on_object_is_null),
            cmocka_unit_test(check_as_settable_list_error_on_out_is_null),
            cmocka_unit_test(check_as_settable_list),
            cmocka_unit_test(check_as_ordered_incremental_list_error_on_object_is_null),
            cmocka_unit_test(check_as_ordered_incremental_list_error_on_out_is_null),
            cmocka_unit_test(check_as_ordered_incremental_list),
            cmocka_unit_test(check_as_ordered_settable_list_error_on_object_is_null),
            cmocka_unit_test(check_as_ordered_settable_list_error_on_out_is_null),
            cmocka_unit_test(check_as_ordered_settable_list),
            cmocka_unit_test(check_as_settable_incremental_list_error_on_object_is_null),
            cmocka_unit_test(check_as_settable_incremental_list_error_on_out_is_null),
            cmocka_unit_test(check_as_settable_incremental_list),
            cmocka_unit_test(check_settable_incremental_list_as_settable_list),
            cmocka_unit_test(check_settable_incremental_list_as_incremental_list),
            cmocka_unit_test(check_incremental_list_as_list),
            cmocka_unit_test(check_addable_as_collection),
            cmocka_unit_test(check_ordered_settable_list_as_ordered_list),
            cmocka_unit_test(check_settable_list_as_list),
            cmocka_unit_test(check_insertable_as_ordered),
            cmocka_unit_test(check_ordered_as_collection),
            cmocka_unit_test(check_settable_as_collection),
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
            cmocka_unit_test(check_set_error_on_object_is_null),
            cmocka_unit_test(check_set_error_on_value_is_null),
            cmocka_unit_test(check_set_error_on_index_out_of_bounds),
            cmocka_unit_test(check_set_error_on_memory_allocation_failed),
            cmocka_unit_test(check_set_error_on_value_is_invalid),
            cmocka_unit_test(check_set_item_error_on_object_is_null),
            cmocka_unit_test(check_set_item_error_on_item_is_null),
            cmocka_unit_test(check_set_item_error_on_value_is_null),
            cmocka_unit_test(check_set_item_error_on_memory_allocation_failed),
            cmocka_unit_test(check_set_item_error_on_value_is_invalid),
            cmocka_unit_test(check_add_error_on_object_is_null),
            cmocka_unit_test(check_add_error_on_value_is_null),
            cmocka_unit_test(check_add_error_on_memory_allocation_failed),
            cmocka_unit_test(check_add_error_on_value_is_invalid),
            cmocka_unit_test(check_add_all_error_on_object_is_null),
            cmocka_unit_test(check_add_all_error_on_other_is_null),
            cmocka_unit_test(check_add_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_insert_error_on_object_is_null),
            cmocka_unit_test(check_insert_error_on_item_is_null),
            cmocka_unit_test(check_insert_error_on_value_is_null),
            cmocka_unit_test(check_insert_error_on_value_is_invalid),
            cmocka_unit_test(check_insert_error_on_memory_allocation_failed),
            cmocka_unit_test(check_insert_all_error_on_object_is_null),
            cmocka_unit_test(check_insert_all_error_on_item_is_null),
            cmocka_unit_test(check_insert_all_error_on_other_is_null),
            cmocka_unit_test(check_insert_all_error_on_memory_allocation_failed),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
