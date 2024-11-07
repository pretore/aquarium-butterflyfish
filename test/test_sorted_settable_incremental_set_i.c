#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

struct object {
    const struct butterflyfish_sorted_settable_incremental_set_i *const
            sorted_settable_incremental_set_i;
    const struct butterflyfish_settable_incremental_set_i *const
            settable_incremental_set_i;
    const struct butterflyfish_sorted_incremental_set_i *const
            sorted_incremental_set_i;
    const struct butterflyfish_sorted_settable_set_i *const
            sorted_settable_set_i;
    const struct butterflyfish_incremental_set_i *const incremental_set_i;
    const struct butterflyfish_settable_set_i *const settable_set_i;
    const struct butterflyfish_sorted_set_i *const sorted_set_i;
    const struct butterflyfish_addable_i *const addable_i;
    const struct butterflyfish_settable_i *const settable_i;
    const struct butterflyfish_set_i *const set_i;
    const struct butterflyfish_sorted_i *const sorted_i;
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
        .lower = sorted_lower
};

static int
set_as_collection(const struct butterflyfish_set_i *const object,
                  const struct butterflyfish_collection_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, set_i, collection_i);
    return 0;
}

static int set_contains(const struct butterflyfish_set_i *const object,
                        const struct sea_turtle_integer *const value,
                        bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static int set_contains_all(const struct butterflyfish_set_i *const object,
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
        .get = set_get
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
        .set_item = settable_set_item,
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
        .add_all = addable_add_all,
};

static int
sorted_set_as_sorted(const struct butterflyfish_sorted_set_i *const object,
                     const struct butterflyfish_sorted_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, sorted_set_i, sorted_i);
    return 0;
}

static int
sorted_set_as_set(const struct butterflyfish_sorted_set_i *const object,
                  const struct butterflyfish_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, sorted_set_i, set_i);
    return 0;
}

const struct butterflyfish_sorted_set_i sorted_set_i = {
        .as_sorted = sorted_set_as_sorted,
        .as_set = sorted_set_as_set,
};

static int
settable_set_as_set(const struct butterflyfish_settable_set_i *const object,
                    const struct butterflyfish_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, settable_set_i, set_i);
    return 0;
}

static int
settable_set_as_settable(struct butterflyfish_settable_set_i *const object,
                         struct butterflyfish_settable_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, settable_set_i,
                              settable_i);
    return 0;
}

static int
settable_set_set(struct butterflyfish_settable_set_i *const object,
                 const struct sea_turtle_integer *const item,
                 const struct sea_turtle_integer *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(value);
    return mock();
}

const struct butterflyfish_settable_set_i settable_set_i = {
        .as_settable = settable_set_as_settable,
        .as_set = settable_set_as_set,
        .set = settable_set_set,
};

static int
incremental_set_as_addable(
        struct butterflyfish_incremental_set_i *const object,
        struct butterflyfish_addable_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, incremental_set_i,
                              addable_i);
    return 0;
}

static int
incremental_set_as_set(
        const struct butterflyfish_incremental_set_i *const object,
        const struct butterflyfish_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, incremental_set_i, set_i);
    return 0;
}

const struct butterflyfish_incremental_set_i incremental_set_i = {
        .as_addable = incremental_set_as_addable,
        .as_set = incremental_set_as_set,
};

static int
sorted_settable_set_as_settable_set(
        struct butterflyfish_sorted_settable_set_i *const object,
        struct butterflyfish_settable_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, sorted_settable_set_i,
                              settable_set_i);
    return 0;
}

static int
sorted_settable_set_as_sorted_set(
        const struct butterflyfish_sorted_settable_set_i *const object,
        const struct butterflyfish_sorted_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, sorted_settable_set_i,
                              sorted_set_i);
    return 0;
}

const struct butterflyfish_sorted_settable_set_i sorted_settable_set_i = {
        .as_settable_set = sorted_settable_set_as_settable_set,
        .as_sorted_set = sorted_settable_set_as_sorted_set,
};

static int
sorted_incremental_set_as_incremental_set(
        struct butterflyfish_sorted_incremental_set_i *const object,
        struct butterflyfish_incremental_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, sorted_incremental_set_i,
                              incremental_set_i);
    return 0;
}

static int
sorted_incremental_set_as_sorted_set(
        const struct butterflyfish_sorted_incremental_set_i *const object,
        const struct butterflyfish_sorted_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, sorted_incremental_set_i,
                              sorted_set_i);
    return 0;
}

const struct
butterflyfish_sorted_incremental_set_i sorted_incremental_set_i = {
        .as_incremental_set = sorted_incremental_set_as_incremental_set,
        .as_sorted_set = sorted_incremental_set_as_sorted_set,
};

static int
settable_incremental_set_as_incremental_set(
        struct butterflyfish_settable_incremental_set_i *const object,
        struct butterflyfish_incremental_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            settable_incremental_set_i, incremental_set_i);
    return 0;
}

static int
settable_incremental_set_as_settable_set(
        struct butterflyfish_settable_incremental_set_i *const object,
        struct butterflyfish_settable_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            settable_incremental_set_i, settable_set_i);
    return 0;
}

const struct
butterflyfish_settable_incremental_set_i settable_incremental_set_i = {
        .as_incremental_set = settable_incremental_set_as_incremental_set,
        .as_settable_set = settable_incremental_set_as_settable_set,
};

static int
sorted_settable_incremental_set_as_settable_incremental_set(
        struct butterflyfish_sorted_settable_incremental_set_i *const object,
        struct butterflyfish_settable_incremental_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              sorted_settable_incremental_set_i,
                              settable_incremental_set_i);
    return 0;
}

static int
sorted_settable_incremental_set_as_sorted_incremental_set(
        struct butterflyfish_sorted_settable_incremental_set_i *const object,
        struct butterflyfish_sorted_incremental_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              sorted_settable_incremental_set_i,
                              sorted_incremental_set_i);
    return 0;
}

static int
sorted_settable_incremental_set_as_sorted_settable_set(
        struct butterflyfish_sorted_settable_incremental_set_i *const object,
        struct butterflyfish_sorted_settable_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              sorted_settable_incremental_set_i,
                              sorted_settable_set_i);
    return 0;
}

const struct butterflyfish_sorted_settable_incremental_set_i
sorted_settable_incremental_set_i = {
        .as_settable_incremental_set =
                sorted_settable_incremental_set_as_settable_incremental_set,
        .as_sorted_incremental_set =
                sorted_settable_incremental_set_as_sorted_incremental_set,
        .as_sorted_settable_set =
                sorted_settable_incremental_set_as_sorted_settable_set,
};

static void check_as_stream_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_as_stream(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_stream_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_as_stream(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_stream(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance + offsetof(struct object, stream_i);
    const struct butterflyfish_stream_i *out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_i_as_stream(
            (const struct butterflyfish_sorted_settable_incremental_set_i *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_collection_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_as_collection(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_collection_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_as_collection(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_collection(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, collection_i);
    const struct butterflyfish_collection_i *out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_i_as_collection(
            (const struct butterflyfish_sorted_settable_incremental_set_i *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_sorted_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_as_sorted(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_sorted_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_as_sorted(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_sorted(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance + offsetof(struct object, sorted_i);
    const struct butterflyfish_sorted_i *out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_i_as_sorted(
            (const struct butterflyfish_sorted_settable_incremental_set_i *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_as_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_as_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_set(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance + offsetof(struct object, set_i);
    const struct butterflyfish_set_i *out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_i_as_set(
            (const struct butterflyfish_sorted_settable_incremental_set_i *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_settable_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_as_settable(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_settable_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_as_settable(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_settable(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, settable_i);
    struct butterflyfish_settable_i *out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_i_as_settable(
            (struct butterflyfish_sorted_settable_incremental_set_i *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_addable_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_as_addable(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_addable_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_as_addable(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_addable(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, addable_i);
    struct butterflyfish_addable_i *out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_i_as_addable(
            (struct butterflyfish_sorted_settable_incremental_set_i *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_sorted_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_as_sorted_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_sorted_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_as_sorted_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_sorted_set(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, sorted_set_i);
    const struct butterflyfish_sorted_set_i *out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_i_as_sorted_set(
            (const struct butterflyfish_sorted_settable_incremental_set_i *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_settable_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_as_settable_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_settable_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_as_settable_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_settable_set(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, settable_set_i);
    struct butterflyfish_settable_set_i *out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_i_as_settable_set(
            (struct butterflyfish_sorted_settable_incremental_set_i *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_incremental_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_as_incremental_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_incremental_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_as_incremental_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_incremental_set(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, incremental_set_i);
    struct butterflyfish_incremental_set_i *out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_i_as_incremental_set(
                    (struct butterflyfish_sorted_settable_incremental_set_i *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_sorted_settable_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_as_sorted_settable_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_sorted_settable_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_as_sorted_settable_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_sorted_settable_set(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, sorted_settable_set_i);
    struct butterflyfish_sorted_settable_set_i *out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_i_as_sorted_settable_set(
                    (struct butterflyfish_sorted_settable_incremental_set_i *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_sorted_incremental_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_as_sorted_incremental_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_sorted_incremental_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_as_sorted_incremental_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_sorted_incremental_set(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, sorted_incremental_set_i);
    struct butterflyfish_sorted_incremental_set_i *out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_i_as_sorted_incremental_set(
                    (struct butterflyfish_sorted_settable_incremental_set_i *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_settable_incremental_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_as_settable_incremental_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_settable_incremental_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_as_settable_incremental_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_settable_incremental_set(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, settable_incremental_set_i);
    struct butterflyfish_settable_incremental_set_i *out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_i_as_settable_incremental_set(
                    (struct butterflyfish_sorted_settable_incremental_set_i *)
                    &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_settable_incremental_set_as_settable_set(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, settable_set_i);
    struct butterflyfish_settable_incremental_set_i *as;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_i_as_settable_incremental_set(
            (struct butterflyfish_sorted_settable_incremental_set_i *)
                    &instance, &as), 0);
    struct butterflyfish_settable_set_i *out;
    assert_int_equal(butterflyfish_settable_incremental_set_i_as_settable_set(
            as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_sorted_incremental_set_as_sorted_set(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, sorted_set_i);
    struct butterflyfish_sorted_incremental_set_i *as;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_i_as_sorted_incremental_set(
            (struct butterflyfish_sorted_settable_incremental_set_i *)
                    &instance, &as), 0);
    const struct butterflyfish_sorted_set_i *out;
    assert_int_equal(butterflyfish_sorted_incremental_set_i_as_sorted_set(
            as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_sorted_incremental_set_as_incremental_set(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, incremental_set_i);
    struct butterflyfish_sorted_incremental_set_i *as;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_i_as_sorted_incremental_set(
            (struct butterflyfish_sorted_settable_incremental_set_i *)
                    &instance, &as), 0);
    struct butterflyfish_incremental_set_i *out;
    assert_int_equal(butterflyfish_sorted_incremental_set_i_as_incremental_set(
            as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_incremental_set_as_set(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance + offsetof(struct object, set_i);
    struct butterflyfish_incremental_set_i *as;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_i_as_incremental_set(
            (struct butterflyfish_sorted_settable_incremental_set_i *)
                    &instance, &as), 0);
    const struct butterflyfish_set_i *out;
    assert_int_equal(butterflyfish_incremental_set_i_as_set(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_sorted_set_as_set(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance + offsetof(struct object, set_i);
    const struct butterflyfish_sorted_set_i *as;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_i_as_sorted_set(
            (const struct butterflyfish_sorted_settable_incremental_set_i *)
                    &instance, &as), 0);
    const struct butterflyfish_set_i *out;
    assert_int_equal(butterflyfish_sorted_set_i_as_set(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_addable_as_collection(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, collection_i);
    struct butterflyfish_addable_i *as;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_i_as_addable(
            (struct butterflyfish_sorted_settable_incremental_set_i *)
                    &instance, &as), 0);
    const struct butterflyfish_collection_i *out;
    assert_int_equal(butterflyfish_addable_i_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_settable_as_collection(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, collection_i);
    struct butterflyfish_settable_i *as;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_i_as_settable(
            (struct butterflyfish_sorted_settable_incremental_set_i *)
                    &instance, &as), 0);
    const struct butterflyfish_collection_i *out;
    assert_int_equal(butterflyfish_settable_i_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_sorted_as_collection(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, collection_i);
    const struct butterflyfish_sorted_i *as;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_i_as_sorted(
            (const struct butterflyfish_sorted_settable_incremental_set_i *)
                    &instance, &as), 0);
    const struct butterflyfish_collection_i *out;
    assert_int_equal(butterflyfish_sorted_i_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_count(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_count(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OUT_IS_NULL);
}

static void check_count(void **state) {
    srand(time(NULL));
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(collection_count);
    const uintmax_t check = abs(rand());
    will_return(collection_count, check);
    uintmax_t out;
    assert_int_equal(butterflyfish_sorted_settable_incremental_set_i_count(
            (const struct butterflyfish_sorted_settable_incremental_set_i *)
                    &instance, &out), 0);
    assert_int_equal(out, check);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_first(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_first(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_set_is_empty(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(stream_first);
    will_return(stream_first,
                BUTTERFLYFISH_STREAM_I_ERROR_STREAM_IS_EMPTY);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_first(
                    (const struct butterflyfish_sorted_settable_incremental_set_i *)
                            &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_SET_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_last(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_last(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_set_is_empty(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(collection_last);
    will_return(collection_last,
                BUTTERFLYFISH_COLLECTION_I_ERROR_COLLECTION_IS_EMPTY);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_last(
                    (const struct butterflyfish_sorted_settable_incremental_set_i *)
                            &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_SET_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_next(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_next(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_next(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OUT_IS_NULL);
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(stream_next);
    will_return(stream_next,
                BUTTERFLYFISH_STREAM_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_next(
                    (const struct butterflyfish_sorted_settable_incremental_set_i *)
                            &instance, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_prev(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_prev(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_prev(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(collection_prev);
    will_return(collection_prev,
                BUTTERFLYFISH_COLLECTION_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_prev(
                    (const struct butterflyfish_sorted_settable_incremental_set_i *)
                            &instance, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_END_OF_SEQUENCE);
}

static void check_contains_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_contains(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_contains_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_contains(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_contains_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_contains(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OUT_IS_NULL);
}

static void check_contains_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(set_contains);
    will_return(set_contains,
                BUTTERFLYFISH_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_contains(
                    (const struct butterflyfish_sorted_settable_incremental_set_i *)
                            &instance, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_contains_all(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_contains_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_contains_all(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OTHER_IS_NULL);
}

static void check_contains_all_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_contains_all(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OUT_IS_NULL);
}

static void
check_contains_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(set_contains_all);
    will_return(set_contains_all,
                BUTTERFLYFISH_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_contains_all(
                    (const struct butterflyfish_sorted_settable_incremental_set_i *)
                            &instance, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_get(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_get(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_get(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OUT_IS_NULL);
}

static void check_get_error_on_value_not_found(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(set_get);
    will_return(set_get,
                BUTTERFLYFISH_SET_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_get(
                    (const struct butterflyfish_sorted_settable_incremental_set_i *)
                            &instance, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_VALUE_NOT_FOUND);
}

static void check_get_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(set_get);
    will_return(set_get,
                BUTTERFLYFISH_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_get(
                    (const struct butterflyfish_sorted_settable_incremental_set_i *)
                            &instance, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_set_item_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_set_item(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_set_item_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_set_item(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_ITEM_IS_NULL);
}

static void check_set_item_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_set_item(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_set_item_error_on_value_is_invalid(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(settable_set_item);
    will_return(settable_set_item,
                BUTTERFLYFISH_SETTABLE_I_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_set_item(
                    (struct butterflyfish_sorted_settable_incremental_set_i
                            *) &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_VALUE_IS_INVALID);
}

static void check_set_item_error_on_value_already_exists(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(settable_set_item);
    will_return(settable_set_item,
                BUTTERFLYFISH_SETTABLE_I_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_set_item(
                    (struct butterflyfish_sorted_settable_incremental_set_i
                            *) &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_VALUE_ALREADY_EXISTS);
}

static void check_set_item_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(settable_set_item);
    will_return(settable_set_item,
                BUTTERFLYFISH_SETTABLE_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_set_item(
                    (struct butterflyfish_sorted_settable_incremental_set_i
                            *) &instance, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_set(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_set_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_set(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_ITEM_IS_NULL);
}

static void check_set_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_set(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_set_error_on_value_not_found(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(settable_set_set);
    will_return(settable_set_set,
                BUTTERFLYFISH_SETTABLE_SET_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_set(
                    (struct butterflyfish_sorted_settable_incremental_set_i
                            *) &instance, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_VALUE_NOT_FOUND);
}

static void check_set_error_on_value_is_invalid(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(settable_set_set);
    will_return(settable_set_set,
                BUTTERFLYFISH_SETTABLE_SET_I_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_set(
                    (struct butterflyfish_sorted_settable_incremental_set_i
                            *) &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_VALUE_IS_INVALID);
}

static void check_set_error_on_value_already_exists(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(settable_set_set);
    will_return(settable_set_set,
                BUTTERFLYFISH_SETTABLE_SET_I_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_set(
                    (struct butterflyfish_sorted_settable_incremental_set_i
                            *) &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_VALUE_ALREADY_EXISTS);
}

static void check_set_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(settable_set_set);
    will_return(settable_set_set,
                BUTTERFLYFISH_SETTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_set(
                    (struct butterflyfish_sorted_settable_incremental_set_i
                            *) &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_add_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_add(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_add_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_add(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_add_error_on_value_is_invalid(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(addable_add);
    will_return(addable_add,
                BUTTERFLYFISH_ADDABLE_I_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_add(
                    (struct butterflyfish_sorted_settable_incremental_set_i
                            *) &instance, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_VALUE_IS_INVALID);
}

static void check_add_error_on_value_already_exists(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(addable_add);
    will_return(addable_add,
                BUTTERFLYFISH_ADDABLE_I_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_add(
                    (struct butterflyfish_sorted_settable_incremental_set_i
                            *) &instance, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_VALUE_ALREADY_EXISTS);
}

static void check_add_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(addable_add);
    will_return(addable_add,
                BUTTERFLYFISH_ADDABLE_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_add(
                    (struct butterflyfish_sorted_settable_incremental_set_i
                            *) &instance, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_add_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_add_all(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_add_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_add_all(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OTHER_IS_NULL);
}

static void check_add_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(addable_add_all);
    will_return(addable_add_all,
                BUTTERFLYFISH_ADDABLE_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_add_all(
                    (struct butterflyfish_sorted_settable_incremental_set_i *)
                            &instance, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_ceiling_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_ceiling(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_ceiling_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_ceiling(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_ceiling_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_ceiling(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OUT_IS_NULL);
}

static void check_ceiling_error_on_value_not_found(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(sorted_ceiling);
    will_return(sorted_ceiling,
                BUTTERFLYFISH_SORTED_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_ceiling(
                    (const struct butterflyfish_sorted_settable_incremental_set_i *)
                            &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_VALUE_NOT_FOUND);
}

static void check_ceiling_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(sorted_ceiling);
    will_return(sorted_ceiling,
                BUTTERFLYFISH_SORTED_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_ceiling(
                    (const struct butterflyfish_sorted_settable_incremental_set_i *)
                            &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_floor_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_floor(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_floor_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_floor(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_floor_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_floor(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OUT_IS_NULL);
}

static void check_floor_error_on_value_not_found(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(sorted_floor);
    will_return(sorted_floor,
                BUTTERFLYFISH_SORTED_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_floor(
                    (const struct butterflyfish_sorted_settable_incremental_set_i *)
                            &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_VALUE_NOT_FOUND);
}

static void check_floor_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(sorted_floor);
    will_return(sorted_floor,
                BUTTERFLYFISH_SORTED_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_floor(
                    (const struct butterflyfish_sorted_settable_incremental_set_i *)
                            &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_higher_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_higher(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_higher_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_higher(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_higher_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_higher(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OUT_IS_NULL);
}

static void check_higher_error_on_value_not_found(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(sorted_higher);
    will_return(sorted_higher,
                BUTTERFLYFISH_SORTED_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_higher(
                    (const struct butterflyfish_sorted_settable_incremental_set_i *)
                            &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_VALUE_NOT_FOUND);
}

static void check_higher_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(sorted_higher);
    will_return(sorted_higher,
                BUTTERFLYFISH_SORTED_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_higher(
                    (const struct butterflyfish_sorted_settable_incremental_set_i *)
                            &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_lower_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_lower(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_lower_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_lower(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_lower_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_lower(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_OUT_IS_NULL);
}

static void check_lower_error_on_value_not_found(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(sorted_lower);
    will_return(sorted_lower,
                BUTTERFLYFISH_SORTED_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_lower(
                    (const struct butterflyfish_sorted_settable_incremental_set_i *)
                            &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_VALUE_NOT_FOUND);
}

static void check_lower_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_settable_incremental_set_i =
                    &sorted_settable_incremental_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .sorted_incremental_set_i = &sorted_incremental_set_i,
            .sorted_settable_set_i = &sorted_settable_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .sorted_set_i = &sorted_set_i,
            .addable_i = &addable_i,
            .settable_i = &settable_i,
            .set_i = &set_i,
            .sorted_i = &sorted_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(sorted_lower);
    will_return(sorted_lower,
                BUTTERFLYFISH_SORTED_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_settable_incremental_set_i_lower(
                    (const struct butterflyfish_sorted_settable_incremental_set_i *)
                            &instance,(void *) 1,(void *) 1),
            BUTTERFLYFISH_SORTED_SETTABLE_INCREMENTAL_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
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
