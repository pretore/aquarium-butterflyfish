#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

static void check_as_stream_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_as_stream(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL);
}

static void check_as_stream_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_as_stream((void *) 1, NULL),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL);
}

static void check_as_stream(void **state) {
    struct butterflyfish_map_sr_sr map = {};
    const struct butterflyfish_stream_sr_sr *stream;
    assert_int_equal(butterflyfish_map_sr_sr_as_stream(&map, &stream), 0);
    assert_ptr_equal(&map, stream);
}

static void check_as_collection_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_as_collection(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL);
}

static void check_as_collection_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_as_collection((void *) 1, NULL),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL);
}

static void check_as_collection(void **state) {
    struct butterflyfish_map_sr_sr map = {};
    const struct butterflyfish_collection_sr_sr *collection;
    assert_int_equal(butterflyfish_map_sr_sr_as_collection(
            &map, &collection), 0);
    assert_ptr_equal(&map, collection);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_count(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_count((void *) 1, NULL),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL);
}

static int count(const void *const object, uintmax_t *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    *out = mock();
    return 0;
}

static void check_count(void **state) {
    srand(time(NULL));
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .collection_sr_sr.count = count
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_map_sr_sr_count(
                    (const struct butterflyfish_map_sr_sr *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static void check_as_collection_count(void **state) {
    srand(time(NULL));
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .collection_sr_sr.count = count
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_collection_sr_sr_count(
                    (const struct butterflyfish_collection_sr_sr *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_first(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_first((void *) 1, NULL),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL);
}

static int
fl_emit_error(const void *const object,
              struct butterflyfish_map_entry_sr_sr **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_first_error_on_map_is_empty(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .collection_sr_sr.stream_sr_sr.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_map_sr_sr_first(
                    (const struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_MAP_IS_EMPTY);
}

static void
check_as_collection_first_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .collection_sr_sr.stream_sr_sr.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_sr_sr_first(
                    (const struct butterflyfish_collection_sr_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_COLLECTION_IS_EMPTY);
}

static void check_as_stream_first_error_on_stream_is_empty(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .collection_sr_sr.stream_sr_sr.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stream_sr_sr_first(
                    (const struct butterflyfish_stream_sr_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_SR_SR_ERROR_STREAM_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_last(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_last((void *) 1, NULL),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_map_is_empty(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .collection_sr_sr.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_map_sr_sr_last(
                    (const struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_MAP_IS_EMPTY);
}

static void
check_as_collection_last_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .collection_sr_sr.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_sr_sr_last(
                    (const struct butterflyfish_collection_sr_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_COLLECTION_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_entry_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_ENTRY_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL);
}

static int
np_emit_error(const void *const object,
              const struct butterflyfish_map_entry_sr_sr *const entry,
              struct butterflyfish_map_entry_sr_sr **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(entry);
    assert_non_null(out);
    return mock();
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .collection_sr_sr.stream_sr_sr.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_map_sr_sr_next(
                    (const struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .collection_sr_sr.stream_sr_sr.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_sr_sr_next(
                    (const struct butterflyfish_collection_sr_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_END_OF_SEQUENCE);
}

static void check_as_stream_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .collection_sr_sr.stream_sr_sr.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stream_sr_sr_next(
                    (const struct butterflyfish_stream_sr_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_SR_SR_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_entry_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_ENTRY_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .collection_sr_sr.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_map_sr_sr_prev(
                    (const struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .collection_sr_sr.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_sr_sr_prev(
                    (const struct butterflyfish_collection_sr_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_END_OF_SEQUENCE);
}

static void check_remove_entry_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_remove_entry(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL);
}

static void check_remove_entry_error_on_entry_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_remove_entry((void *) 1, NULL),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_ENTRY_IS_NULL);
}

static int
remove_entry(void *const object,
             const struct butterflyfish_map_entry_sr_sr *const entry) {
    function_called();
    assert_non_null(object);
    assert_non_null(entry);
    return 0;
}

static void check_remove_entry(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .remove_entry = remove_entry
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(remove_entry);
    assert_int_equal(
            butterflyfish_map_sr_sr_remove_entry(
                    (struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1),
            0);
}

static void check_remove_all_entries_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_remove_all_entries(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_entries_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_remove_all_entries((void *) 1, NULL),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OTHER_IS_NULL);
}

static int
remove_all_entries(void *const object,
                   const struct butterflyfish_stream_sr_sr *const stream) {
    function_called();
    assert_non_null(object);
    assert_non_null(stream);
    return 0;
}

static void check_remove_all_entries(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .remove_all_entries = remove_all_entries
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(remove_all_entries);
    assert_int_equal(
            butterflyfish_map_sr_sr_remove_all_entries(
                    (struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1),
            0);
}

static void check_add_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_add(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL);
}

static void check_add_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_add((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_IS_NULL);
}

static void check_add_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_add((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_VALUE_IS_NULL);
}

static int apr_emit_error(void *const object,
                          struct triggerfish_strong *const key,
                          struct triggerfish_strong *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(key);
    assert_non_null(value);
    return mock();
}

static void check_add_error_on_key_already_exists(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .add = apr_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_map_sr_sr_add(
                    (struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_ALREADY_EXISTS);
}

static void check_add_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .add = apr_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_sr_sr_add(
                    (struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_put_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_put(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL);
}

static void check_put_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_put((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_IS_NULL);
}

static void check_put_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_put((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_VALUE_IS_NULL);
}

static void check_put_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .put = apr_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_sr_sr_put(
                    (struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_replace_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_replace(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL);
}

static void check_replace_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_replace((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_IS_NULL);
}

static void check_replace_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_replace((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_VALUE_IS_NULL);
}

static void check_replace_error_on_key_not_found(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .replace = apr_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_map_sr_sr_replace(
                    (struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_NOT_FOUND);
}

static void check_replace_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .replace = apr_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_sr_sr_replace(
                    (struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_remove(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL);
}

static void check_remove_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_remove((void *) 1, NULL),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_IS_NULL);
}

static int remove_emit_error(void *const object,
                             struct triggerfish_strong *const key) {
    function_called();
    assert_non_null(object);
    assert_non_null(key);
    return mock();
}

static void check_remove_error_on_key_not_found(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_map_sr_sr_remove(
                    (struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_NOT_FOUND);
}

static void check_remove_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_sr_sr_remove(
                    (struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_add_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_add_all(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL);
}

static void check_add_all_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_add_all((void *) 1, NULL),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OTHER_IS_NULL);
}

static int
all_emit_error(void *const object,
               const struct butterflyfish_stream_sr_sr *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static void check_add_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .add_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_sr_sr_add_all(
                    (struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_put_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_put_all(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL);
}

static void check_put_all_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_put_all((void *) 1, NULL),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OTHER_IS_NULL);
}

static void check_put_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .put_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_sr_sr_put_all(
                    (struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_replace_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_replace_all(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL);
}

static void check_replace_all_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_replace_all((void *) 1, NULL),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OTHER_IS_NULL);
}

static void check_replace_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .replace_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_sr_sr_replace_all(
                    (struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_remove_all(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_remove_all((void *) 1, NULL),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OTHER_IS_NULL);
}

static int
rr_all_emit_error(void *const object,
                  const struct butterflyfish_stream_sr *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static void check_remove_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .remove_all = rr_all_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(rr_all_emit_error);
    will_return(rr_all_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_sr_sr_remove_all(
                    (struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_retain_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_retain_all(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL);
}

static void check_retain_all_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_retain_all((void *) 1, NULL),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OTHER_IS_NULL);
}

static void check_retain_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .retain_all = rr_all_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(rr_all_emit_error);
    will_return(rr_all_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_sr_sr_retain_all(
                    (struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_merge_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_merge(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL);
}

static void check_merge_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_merge((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OTHER_IS_NULL);
}

static void check_merge_error_on_function_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_merge((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_FUNCTION_IS_NULL);
}

static int
merge_emit_error(void *const object,
                 const struct butterflyfish_stream_sr_sr *const other,
                 int (*const function)(
                         const struct triggerfish_strong *,
                         const struct triggerfish_strong *,
                         struct triggerfish_strong **)) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    assert_non_null(function);
    return mock();
}

static void check_merge_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .merge = merge_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(merge_emit_error);
    will_return(merge_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_sr_sr_merge(
                    (struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_key_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_contains_key(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL);
}

static void check_contains_key_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_contains_key((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_IS_NULL);
}

static void check_contains_key_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_contains_key((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL);
}

static int
contains_key_emit_error(const void *const object,
                        struct triggerfish_strong *const key,
                        bool *out) {
    function_called();
    assert_non_null(object);
    assert_non_null(key);
    assert_non_null(out);
    return mock();
}

static void
check_contains_key_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .contains_key = contains_key_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(contains_key_emit_error);
    will_return(contains_key_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_sr_sr_contains_key(
                    (struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_all_keys_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_contains_all_keys(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL);
}

static void check_contains_all_keys_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_contains_all_keys(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OTHER_IS_NULL);
}

static void check_contains_all_keys_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_contains_all_keys(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL);
}

static int
contains_all_keys_emit_error(const void *const object,
                             const struct butterflyfish_stream_sr *const other,
                             bool *out) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    assert_non_null(out);
    return mock();
}

static void
check_contains_all_keys_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .contains_all_keys = contains_all_keys_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(contains_all_keys_emit_error);
    will_return(contains_all_keys_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_sr_sr_contains_all_keys(
                    (struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_get(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_get((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_get((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL);
}

static int get_emit_error(const void *const object,
                          struct triggerfish_strong *const key,
                          struct triggerfish_strong **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(key);
    assert_non_null(out);
    return mock();
}

static void check_get_error_on_key_not_found(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .get = get_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_map_sr_sr_get(
                    (struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_NOT_FOUND);
}

static void check_get_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .get = get_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_sr_sr_get(
                    (struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_entry_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_get_entry(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL);
}

static void check_get_entry_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_get_entry((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_IS_NULL);
}

static void check_get_entry_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_get_entry((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL);
}

static int
get_entry_emit_error(const void *const object,
                     struct triggerfish_strong *const key,
                     struct butterflyfish_map_entry_sr_sr **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(key);
    assert_non_null(out);
    return mock();
}

static void check_get_entry_error_on_key_not_found(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .get_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_map_sr_sr_get_entry(
                    (struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_NOT_FOUND);
}

static void check_get_entry_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .get_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_sr_sr_get_entry(
                    (struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_keys_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_keys(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL);
}

static void check_keys_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_keys((void *) 1, NULL),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL);
}

static int keys(void *const object,
                struct butterflyfish_set_sr **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return 0;
}

static void check_keys(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .keys = keys
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(keys);
    assert_int_equal(
            butterflyfish_map_sr_sr_keys(
                    (struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1),
            0);
}

static void check_values_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_values(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL);
}

static void check_values_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_sr_sr_values((void *) 1, NULL),
            BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL);
}

static int values(void *const object,
                  struct butterflyfish_reducible_list_sr **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return 0;
}

static void check_values(void **state) {
    const struct butterflyfish_map_sr_sr map_sr_sr = {
            .values = values
    };
    struct object {
        const struct butterflyfish_map_sr_sr *map_sr_sr;
    };
    struct object instance = {
            .map_sr_sr = &map_sr_sr
    };
    expect_function_call(values);
    assert_int_equal(
            butterflyfish_map_sr_sr_values(
                    (struct butterflyfish_map_sr_sr *) &instance,
                    (void *) 1),
            0);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_as_stream_error_on_object_is_null),
            cmocka_unit_test(check_as_stream_error_on_out_is_null),
            cmocka_unit_test(check_as_stream),
            cmocka_unit_test(check_as_collection_error_on_object_is_null),
            cmocka_unit_test(check_as_collection_error_on_out_is_null),
            cmocka_unit_test(check_as_collection),
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_count),
            cmocka_unit_test(check_as_collection_count),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_map_is_empty),
            cmocka_unit_test(check_as_collection_first_error_on_collection_is_empty),
            cmocka_unit_test(check_as_stream_first_error_on_stream_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_map_is_empty),
            cmocka_unit_test(check_as_collection_last_error_on_collection_is_empty),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_entry_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_collection_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_stream_next_error_on_end_of_sequence),
            cmocka_unit_test(check_prev_error_on_object_is_null),
            cmocka_unit_test(check_prev_error_on_entry_is_null),
            cmocka_unit_test(check_prev_error_on_out_is_null),
            cmocka_unit_test(check_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_as_collection_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_remove_entry_error_on_object_is_null),
            cmocka_unit_test(check_remove_entry_error_on_entry_is_null),
            cmocka_unit_test(check_remove_entry),
            cmocka_unit_test(check_remove_all_entries_error_on_object_is_null),
            cmocka_unit_test(check_remove_all_entries_error_on_other_is_null),
            cmocka_unit_test(check_remove_all_entries),
            cmocka_unit_test(check_add_error_on_object_is_null),
            cmocka_unit_test(check_add_error_on_key_is_null),
            cmocka_unit_test(check_add_error_on_value_is_null),
            cmocka_unit_test(check_add_error_on_key_already_exists),
            cmocka_unit_test(check_add_error_on_memory_allocation_failed),
            cmocka_unit_test(check_put_error_on_object_is_null),
            cmocka_unit_test(check_put_error_on_key_is_null),
            cmocka_unit_test(check_put_error_on_value_is_null),
            cmocka_unit_test(check_put_error_on_memory_allocation_failed),
            cmocka_unit_test(check_replace_error_on_object_is_null),
            cmocka_unit_test(check_replace_error_on_key_is_null),
            cmocka_unit_test(check_replace_error_on_value_is_null),
            cmocka_unit_test(check_replace_error_on_key_not_found),
            cmocka_unit_test(check_replace_error_on_memory_allocation_failed),
            cmocka_unit_test(check_remove_error_on_object_is_null),
            cmocka_unit_test(check_remove_error_on_key_is_null),
            cmocka_unit_test(check_remove_error_on_key_not_found),
            cmocka_unit_test(check_remove_error_on_memory_allocation_failed),
            cmocka_unit_test(check_add_all_error_on_object_is_null),
            cmocka_unit_test(check_add_all_error_on_key_is_null),
            cmocka_unit_test(check_add_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_put_all_error_on_object_is_null),
            cmocka_unit_test(check_put_all_error_on_key_is_null),
            cmocka_unit_test(check_put_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_replace_all_error_on_object_is_null),
            cmocka_unit_test(check_replace_all_error_on_key_is_null),
            cmocka_unit_test(check_replace_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_remove_all_error_on_object_is_null),
            cmocka_unit_test(check_remove_all_error_on_key_is_null),
            cmocka_unit_test(check_remove_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_retain_all_error_on_object_is_null),
            cmocka_unit_test(check_retain_all_error_on_key_is_null),
            cmocka_unit_test(check_retain_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_merge_error_on_object_is_null),
            cmocka_unit_test(check_merge_error_on_other_is_null),
            cmocka_unit_test(check_merge_error_on_function_is_null),
            cmocka_unit_test(check_merge_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_key_error_on_object_is_null),
            cmocka_unit_test(check_contains_key_error_on_other_is_null),
            cmocka_unit_test(check_contains_key_error_on_out_is_null),
            cmocka_unit_test(check_contains_key_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_all_keys_error_on_object_is_null),
            cmocka_unit_test(check_contains_all_keys_error_on_other_is_null),
            cmocka_unit_test(check_contains_all_keys_error_on_out_is_null),
            cmocka_unit_test(check_contains_all_keys_error_on_memory_allocation_failed),
            cmocka_unit_test(check_get_error_on_object_is_null),
            cmocka_unit_test(check_get_error_on_key_is_null),
            cmocka_unit_test(check_get_error_on_out_is_null),
            cmocka_unit_test(check_get_error_on_key_not_found),
            cmocka_unit_test(check_get_error_on_memory_allocation_failed),
            cmocka_unit_test(check_get_entry_error_on_object_is_null),
            cmocka_unit_test(check_get_entry_error_on_key_is_null),
            cmocka_unit_test(check_get_entry_error_on_out_is_null),
            cmocka_unit_test(check_get_entry_error_on_key_not_found),
            cmocka_unit_test(check_get_entry_error_on_memory_allocation_failed),
            cmocka_unit_test(check_keys_error_on_object_is_null),
            cmocka_unit_test(check_keys_error_on_out_is_null),
            cmocka_unit_test(check_keys),
            cmocka_unit_test(check_values_error_on_object_is_null),
            cmocka_unit_test(check_values_error_on_out_is_null),
            cmocka_unit_test(check_values),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
