#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

struct object {
    const struct butterflyfish_sorted_map_i_i *const sorted_map_i_i;
    const struct butterflyfish_map_i_i *const map_i_i;
    const struct butterflyfish_sorted_i_i *const sorted_i_i;
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

static int
collection_as_stream(const struct butterflyfish_collection_i_i *const object,
                     const struct butterflyfish_stream_i_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, collection_i_i,
            stream_i_i);
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
        .as_stream = collection_as_stream,
        .last = collection_last,
        .prev = collection_prev,
        .count = collection_count,
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
sorted_as_collection(const struct butterflyfish_sorted_i_i *const object,
                     const struct butterflyfish_collection_i_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            sorted_i_i,
            collection_i_i);
    return 0;
}

static int
sorted_ceiling(const struct butterflyfish_sorted_i_i *const object,
               const struct butterflyfish_map_i_i_entry *const value,
               const struct butterflyfish_map_i_i_entry **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static int
sorted_floor(const struct butterflyfish_sorted_i_i *const object,
             const struct butterflyfish_map_i_i_entry *const value,
             const struct butterflyfish_map_i_i_entry **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static int
sorted_higher(const struct butterflyfish_sorted_i_i *const object,
              const struct butterflyfish_map_i_i_entry *const value,
              const struct butterflyfish_map_i_i_entry **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static int
sorted_lower(const struct butterflyfish_sorted_i_i *const object,
             const struct butterflyfish_map_i_i_entry *const value,
             const struct butterflyfish_map_i_i_entry **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_sorted_i_i sorted_i_i = {
        .as_collection = sorted_as_collection,
        .ceiling = sorted_ceiling,
        .floor = sorted_floor,
        .higher = sorted_higher,
        .lower = sorted_lower
};

static int map_as_set(const struct butterflyfish_map_i_i *const object,
                      const struct butterflyfish_set_i_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, map_i_i, set_i_i);
    return 0;
}

static int
map_contains_key(const struct butterflyfish_map_i_i *const object,
                 const struct sea_turtle_integer *const key,
                 bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(key);
    assert_non_null(out);
    return mock();
}

static int
map_contains_value(const struct butterflyfish_map_i_i *const object,
                   const struct sea_turtle_integer *const value,
                   bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static int
map_contains_all_keys(const struct butterflyfish_map_i_i *const object,
                      const struct butterflyfish_stream_i *const other,
                      bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    assert_non_null(out);
    return mock();
}

static int
map_contains_all_values(const struct butterflyfish_map_i_i *const object,
                        const struct butterflyfish_stream_i *const other,
                        bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    assert_non_null(out);
    return mock();
}

static int map_get_value(const struct butterflyfish_map_i_i *const object,
                         const struct sea_turtle_integer *const key,
                         const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(key);
    assert_non_null(out);
    return mock();
}

static int
map_get_entry(const struct butterflyfish_map_i_i *const object,
              const struct sea_turtle_integer *const key,
              const struct butterflyfish_map_i_i_entry **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(key);
    assert_non_null(out);
    return mock();
}

static int map_keys(const struct butterflyfish_map_i_i *const object,
                    const struct butterflyfish_set_i **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int map_values(const struct butterflyfish_map_i_i *const object,
                      const struct butterflyfish_ordered_list_i **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_map_i_i map_i_i = {
        .as_set = map_as_set,
        .contains_key = map_contains_key,
        .contains_value = map_contains_value,
        .contains_all_keys = map_contains_all_keys,
        .contains_all_values = map_contains_all_values,
        .get_value = map_get_value,
        .get_entry = map_get_entry,
        .keys = map_keys,
        .values = map_values,
};

static int
sorted_map_as_map(const struct butterflyfish_sorted_map_i_i *const object,
                  const struct butterflyfish_map_i_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, sorted_map_i_i, map_i_i);
    return 0;
}

static int
sorted_map_as_sorted(const struct butterflyfish_sorted_map_i_i *const object,
                     const struct butterflyfish_sorted_i_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            sorted_map_i_i,
            sorted_i_i);
    return 0;
}

static int
sorted_map_keys(const struct butterflyfish_sorted_map_i_i *const object,
                const struct butterflyfish_sorted_set_i **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int
sorted_map_values(const struct butterflyfish_sorted_map_i_i *const object,
                  const struct butterflyfish_ordered_list_i **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int
sorted_map_ceiling(const struct butterflyfish_sorted_map_i_i *const object,
                   const struct sea_turtle_integer *const value,
                   const struct butterflyfish_map_i_i_entry **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static int
sorted_map_floor(const struct butterflyfish_sorted_map_i_i *const object,
                 const struct sea_turtle_integer *const value,
                 const struct butterflyfish_map_i_i_entry **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static int
sorted_map_higher(const struct butterflyfish_sorted_map_i_i *const object,
                  const struct sea_turtle_integer *const value,
                  const struct butterflyfish_map_i_i_entry **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static int
sorted_map_lower(const struct butterflyfish_sorted_map_i_i *const object,
                 const struct sea_turtle_integer *const value,
                 const struct butterflyfish_map_i_i_entry **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
        .as_map = sorted_map_as_map,
        .as_sorted = sorted_map_as_sorted,
        .ceiling = sorted_map_ceiling,
        .floor = sorted_map_floor,
        .higher = sorted_map_higher,
        .lower = sorted_map_lower,
        .keys = sorted_map_keys,
        .values = sorted_map_values
};

static void check_as_stream_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_as_stream(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_stream_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_as_stream((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_as_stream(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, stream_i_i);
    const struct butterflyfish_stream_i_i *out;
    assert_int_equal(butterflyfish_sorted_map_i_i_as_stream(
            (const struct butterflyfish_sorted_map_i_i *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_collection_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_as_collection(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_collection_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_as_collection((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_as_collection(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, collection_i_i);
    const struct butterflyfish_collection_i_i *out;
    assert_int_equal(butterflyfish_sorted_map_i_i_as_collection(
            (const struct butterflyfish_sorted_map_i_i *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_as_set(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_as_set((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_as_set(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    const void *check = (char *) &instance + offsetof(struct object, set_i_i);
    const struct butterflyfish_set_i_i *out;
    assert_int_equal(butterflyfish_sorted_map_i_i_as_set(
            (const struct butterflyfish_sorted_map_i_i *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_sorted_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_as_sorted(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_sorted_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_as_sorted((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_as_sorted(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, sorted_i_i);
    const struct butterflyfish_sorted_i_i *out;
    assert_int_equal(butterflyfish_sorted_map_i_i_as_sorted(
            (const struct butterflyfish_sorted_map_i_i *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_map_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_as_map(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_map_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_as_map((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_as_map(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, map_i_i);
    const struct butterflyfish_map_i_i *out;
    assert_int_equal(butterflyfish_sorted_map_i_i_as_map(
            (const struct butterflyfish_sorted_map_i_i *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_set_as_collection(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, collection_i_i);
    const struct butterflyfish_set_i_i *as;
    assert_int_equal(butterflyfish_sorted_map_i_i_as_set(
            (struct butterflyfish_sorted_map_i_i *) &instance, &as), 0);
    const struct butterflyfish_collection_i_i *out;
    assert_int_equal(butterflyfish_set_i_i_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_sorted_as_collection(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, collection_i_i);
    const struct butterflyfish_sorted_i_i *as;
    assert_int_equal(butterflyfish_sorted_map_i_i_as_sorted(
            (struct butterflyfish_sorted_map_i_i *) &instance, &as), 0);
    const struct butterflyfish_collection_i_i *out;
    assert_int_equal(butterflyfish_sorted_i_i_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_count(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_count((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_count(void **state) {
    srand(time(NULL));
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(collection_count);
    const uintmax_t check = abs(rand());
    will_return(collection_count, check);
    uintmax_t out;
    assert_int_equal(butterflyfish_sorted_map_i_i_count(
            (const struct butterflyfish_sorted_map_i_i *) &instance, &out), 0);
    assert_int_equal(out, check);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_first(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_first((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_map_is_empty(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(stream_first);
    will_return(stream_first,
                BUTTERFLYFISH_STREAM_I_I_ERROR_STREAM_IS_EMPTY);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_first(
                    (const struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MAP_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_last(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_last((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_map_is_empty(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(collection_last);
    will_return(collection_last,
                BUTTERFLYFISH_COLLECTION_I_I_ERROR_COLLECTION_IS_EMPTY);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_last(
                    (const struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MAP_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(stream_next);
    will_return(stream_next,
                BUTTERFLYFISH_STREAM_I_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_next(
                    (const struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(collection_prev);
    will_return(collection_prev,
                BUTTERFLYFISH_COLLECTION_I_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_prev(
                    (const struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_END_OF_SEQUENCE);
}

static void check_contains_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_contains_error_on_entry_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_ENTRY_IS_NULL);
}

static void check_contains_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_contains_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(set_contains);
    will_return(set_contains,
                BUTTERFLYFISH_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_key_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_key(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_contains_key_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_key((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_VALUE_IS_NULL);
}

static void check_contains_key_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_key((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_contains_key_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(map_contains_key);
    will_return(map_contains_key,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_key(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_value_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_value(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_contains_value_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_value((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_VALUE_IS_NULL);
}

static void check_contains_value_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_value((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_contains_value_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(map_contains_value);
    will_return(map_contains_value,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_value(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_all(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_contains_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_all((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OTHER_IS_NULL);
}

static void check_contains_all_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_all((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void
check_contains_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(set_contains_all);
    will_return(set_contains_all,
                BUTTERFLYFISH_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_all(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_all_keys_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_all_keys(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_contains_all_keys_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_all_keys((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OTHER_IS_NULL);
}

static void check_contains_all_keys_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_all_keys((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void
check_contains_all_keys_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(map_contains_all_keys);
    will_return(map_contains_all_keys,
                BUTTERFLYFISH_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_all_keys(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_all_values_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_all_values(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_contains_all_values_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_all_values((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OTHER_IS_NULL);
}

static void check_contains_all_values_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_all_values((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void
check_contains_all_values_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(map_contains_all_values);
    will_return(map_contains_all_values,
                BUTTERFLYFISH_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_all_values(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_get(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_entry_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_get((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_ENTRY_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_get((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_get_error_on_entry_not_found(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(set_get);
    will_return(set_get,
                BUTTERFLYFISH_SET_I_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_get(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_ENTRY_NOT_FOUND);
}

static void check_get_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(set_get);
    will_return(set_get,
                BUTTERFLYFISH_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_get(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_value_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_get_value(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_get_value_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_get_value((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_VALUE_IS_NULL);
}

static void check_get_value_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_get_value((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_get_value_error_on_value_not_found(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(map_get_value);
    will_return(map_get_value,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_get_value(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_VALUE_NOT_FOUND);
}

static void check_get_value_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(map_get_value);
    will_return(map_get_value,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_get_value(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_entry_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_get_entry(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_get_entry_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_get_entry((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_VALUE_IS_NULL);
}

static void check_get_entry_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_get_entry((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_get_entry_error_on_value_not_found(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(map_get_entry);
    will_return(map_get_entry,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_get_entry(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_VALUE_NOT_FOUND);
}

static void check_get_entry_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(map_get_entry);
    will_return(map_get_entry,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_get_entry(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_ceiling_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_ceiling(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_ceiling_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_ceiling((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL);
}

static void check_ceiling_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_ceiling((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_ceiling_error_on_key_not_found(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(sorted_map_ceiling);
    will_return(sorted_map_ceiling,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_ceiling(
                    (const struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void check_ceiling_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(sorted_map_ceiling);
    will_return(sorted_map_ceiling,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_ceiling(
                    (const struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_floor_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_floor(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_floor_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_floor((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL);
}

static void check_floor_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_floor((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_floor_error_on_key_not_found(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(sorted_map_floor);
    will_return(sorted_map_floor,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_floor(
                    (const struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void check_floor_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(sorted_map_floor);
    will_return(sorted_map_floor,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_floor(
                    (const struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_higher_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_higher(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_higher_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_higher((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL);
}

static void check_higher_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_higher((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_higher_error_on_key_not_found(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(sorted_map_higher);
    will_return(sorted_map_higher,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_higher(
                    (const struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void check_higher_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(sorted_map_higher);
    will_return(sorted_map_higher,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_higher(
                    (const struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_lower_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_lower(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_lower_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_lower((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL);
}

static void check_lower_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_lower((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_lower_error_on_key_not_found(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(sorted_map_lower);
    will_return(sorted_map_lower,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_lower(
                    (const struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void check_lower_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(sorted_map_lower);
    will_return(sorted_map_lower,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_lower(
                    (const struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_sorted_ceiling(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(sorted_ceiling);
    will_return(sorted_ceiling, 0);
    const struct butterflyfish_sorted_i_i *as;
    assert_int_equal(butterflyfish_sorted_map_i_i_as_sorted(
            (struct butterflyfish_sorted_map_i_i *) &instance, &as), 0);
    assert_int_equal(butterflyfish_sorted_i_i_ceiling(
            as, (void *) 1, (void *) 1), 0);
}

static void check_sorted_floor(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(sorted_floor);
    will_return(sorted_floor, 0);
    const struct butterflyfish_sorted_i_i *as;
    assert_int_equal(butterflyfish_sorted_map_i_i_as_sorted(
            (struct butterflyfish_sorted_map_i_i *) &instance, &as), 0);
    assert_int_equal(butterflyfish_sorted_i_i_floor(
            as, (void *) 1, (void *) 1), 0);
}

static void check_sorted_higher(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(sorted_higher);
    will_return(sorted_higher, 0);
    const struct butterflyfish_sorted_i_i *as;
    assert_int_equal(butterflyfish_sorted_map_i_i_as_sorted(
            (struct butterflyfish_sorted_map_i_i *) &instance, &as), 0);
    assert_int_equal(butterflyfish_sorted_i_i_higher(
            as, (void *) 1, (void *) 1), 0);
}

static void check_sorted_lower(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(sorted_lower);
    will_return(sorted_lower, 0);
    const struct butterflyfish_sorted_i_i *as;
    assert_int_equal(butterflyfish_sorted_map_i_i_as_sorted(
            (struct butterflyfish_sorted_map_i_i *) &instance, &as), 0);
    assert_int_equal(butterflyfish_sorted_i_i_lower(
            as, (void *) 1, (void *) 1), 0);
}

static void check_keys_error_on_object_is_null(void **state) {
    assert_int_equal(butterflyfish_sorted_map_i_i_keys(NULL, (void *) 1),
                     BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_keys_error_on_out_is_null(void **state) {
    assert_int_equal(butterflyfish_sorted_map_i_i_keys((void *) 1, NULL),
                     BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_keys(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(sorted_map_keys);
    will_return(sorted_map_keys, 0);
    const struct butterflyfish_sorted_set_i *out;
    assert_int_equal(butterflyfish_sorted_map_i_i_keys(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    &out), 0);
}

static void check_as_map_keys(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(map_keys);
    will_return(map_keys, 0);
    const struct butterflyfish_map_i_i *as;
    assert_int_equal(butterflyfish_sorted_map_i_i_as_map(
            (const struct butterflyfish_sorted_map_i_i *)
                    &instance, &as), 0);
    const struct butterflyfish_set_i *out;
    assert_int_equal(butterflyfish_map_i_i_keys(as, &out), 0);
}

static void check_values_error_on_object_is_null(void **state) {
    assert_int_equal(butterflyfish_sorted_map_i_i_values(NULL, (void *) 1),
                     BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_values_error_on_out_is_null(void **state) {
    assert_int_equal(butterflyfish_sorted_map_i_i_values((void *) 1, NULL),
                     BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_values(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(sorted_map_values);
    will_return(sorted_map_values, 0);
    const struct butterflyfish_ordered_list_i *out;
    assert_int_equal(butterflyfish_sorted_map_i_i_values(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    &out), 0);
}

static void check_as_map_values(void **state) {
    const struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i,
            .sorted_i_i = &sorted_i_i,
            .map_i_i = &map_i_i,
            .set_i_i = &set_i_i,
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(map_values);
    will_return(map_values, 0);
    const struct butterflyfish_map_i_i *as;
    assert_int_equal(butterflyfish_sorted_map_i_i_as_map(
            (struct butterflyfish_sorted_map_i_i *) &instance, &as), 0);
    const struct butterflyfish_ordered_list_i *out;
    assert_int_equal(butterflyfish_map_i_i_values(as, &out), 0);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_as_stream_error_on_object_is_null),
            cmocka_unit_test(check_as_stream_error_on_out_is_null),
            cmocka_unit_test(check_as_stream),
            cmocka_unit_test(check_as_collection_error_on_object_is_null),
            cmocka_unit_test(check_as_collection_error_on_out_is_null),
            cmocka_unit_test(check_as_collection),
            cmocka_unit_test(check_as_set_error_on_object_is_null),
            cmocka_unit_test(check_as_set_error_on_out_is_null),
            cmocka_unit_test(check_as_set),
            cmocka_unit_test(check_as_sorted_error_on_object_is_null),
            cmocka_unit_test(check_as_sorted_error_on_out_is_null),
            cmocka_unit_test(check_as_sorted),
            cmocka_unit_test(check_as_map_error_on_object_is_null),
            cmocka_unit_test(check_as_map_error_on_out_is_null),
            cmocka_unit_test(check_as_map),
            cmocka_unit_test(check_set_as_collection),
            cmocka_unit_test(check_sorted_as_collection),
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_count),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_map_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_map_is_empty),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_item_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
            cmocka_unit_test(check_prev_error_on_object_is_null),
            cmocka_unit_test(check_prev_error_on_item_is_null),
            cmocka_unit_test(check_prev_error_on_out_is_null),
            cmocka_unit_test(check_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_contains_error_on_object_is_null),
            cmocka_unit_test(check_contains_error_on_entry_is_null),
            cmocka_unit_test(check_contains_error_on_out_is_null),
            cmocka_unit_test(check_contains_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_key_error_on_object_is_null),
            cmocka_unit_test(check_contains_key_error_on_value_is_null),
            cmocka_unit_test(check_contains_key_error_on_out_is_null),
            cmocka_unit_test(check_contains_key_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_value_error_on_object_is_null),
            cmocka_unit_test(check_contains_value_error_on_value_is_null),
            cmocka_unit_test(check_contains_value_error_on_out_is_null),
            cmocka_unit_test(check_contains_value_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_all_error_on_object_is_null),
            cmocka_unit_test(check_contains_all_error_on_other_is_null),
            cmocka_unit_test(check_contains_all_error_on_out_is_null),
            cmocka_unit_test(check_contains_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_all_keys_error_on_object_is_null),
            cmocka_unit_test(check_contains_all_keys_error_on_other_is_null),
            cmocka_unit_test(check_contains_all_keys_error_on_out_is_null),
            cmocka_unit_test(check_contains_all_keys_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_all_values_error_on_object_is_null),
            cmocka_unit_test(check_contains_all_values_error_on_other_is_null),
            cmocka_unit_test(check_contains_all_values_error_on_out_is_null),
            cmocka_unit_test(check_contains_all_values_error_on_memory_allocation_failed),
            cmocka_unit_test(check_get_error_on_object_is_null),
            cmocka_unit_test(check_get_error_on_entry_is_null),
            cmocka_unit_test(check_get_error_on_out_is_null),
            cmocka_unit_test(check_get_error_on_entry_not_found),
            cmocka_unit_test(check_get_error_on_memory_allocation_failed),
            cmocka_unit_test(check_get_value_error_on_object_is_null),
            cmocka_unit_test(check_get_value_error_on_value_is_null),
            cmocka_unit_test(check_get_value_error_on_out_is_null),
            cmocka_unit_test(check_get_value_error_on_value_not_found),
            cmocka_unit_test(check_get_value_error_on_memory_allocation_failed),
            cmocka_unit_test(check_get_entry_error_on_object_is_null),
            cmocka_unit_test(check_get_entry_error_on_value_is_null),
            cmocka_unit_test(check_get_entry_error_on_out_is_null),
            cmocka_unit_test(check_get_entry_error_on_value_not_found),
            cmocka_unit_test(check_get_entry_error_on_memory_allocation_failed),
            cmocka_unit_test(check_ceiling_error_on_object_is_null),
            cmocka_unit_test(check_ceiling_error_on_key_is_null),
            cmocka_unit_test(check_ceiling_error_on_out_is_null),
            cmocka_unit_test(check_ceiling_error_on_key_not_found),
            cmocka_unit_test(check_ceiling_error_on_memory_allocation_failed),
            cmocka_unit_test(check_floor_error_on_object_is_null),
            cmocka_unit_test(check_floor_error_on_key_is_null),
            cmocka_unit_test(check_floor_error_on_out_is_null),
            cmocka_unit_test(check_floor_error_on_key_not_found),
            cmocka_unit_test(check_floor_error_on_memory_allocation_failed),
            cmocka_unit_test(check_higher_error_on_object_is_null),
            cmocka_unit_test(check_higher_error_on_key_is_null),
            cmocka_unit_test(check_higher_error_on_out_is_null),
            cmocka_unit_test(check_higher_error_on_key_not_found),
            cmocka_unit_test(check_higher_error_on_memory_allocation_failed),
            cmocka_unit_test(check_lower_error_on_object_is_null),
            cmocka_unit_test(check_lower_error_on_key_is_null),
            cmocka_unit_test(check_lower_error_on_out_is_null),
            cmocka_unit_test(check_lower_error_on_key_not_found),
            cmocka_unit_test(check_lower_error_on_memory_allocation_failed),
            cmocka_unit_test(check_sorted_ceiling),
            cmocka_unit_test(check_sorted_floor),
            cmocka_unit_test(check_sorted_higher),
            cmocka_unit_test(check_sorted_lower),
            cmocka_unit_test(check_keys_error_on_object_is_null),
            cmocka_unit_test(check_keys_error_on_out_is_null),
            cmocka_unit_test(check_keys),
            cmocka_unit_test(check_as_map_keys),
            cmocka_unit_test(check_values_error_on_object_is_null),
            cmocka_unit_test(check_values_error_on_out_is_null),
            cmocka_unit_test(check_values),
            cmocka_unit_test(check_as_map_values),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
