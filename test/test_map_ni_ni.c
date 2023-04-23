#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_count(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_count((void *) 1, NULL),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_first(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_first((void *) 1, NULL),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static int
fl_emit_error(const void *const object,
              const struct butterflyfish_map_entry_ni_ni **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_first_error_on_map_is_empty(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .collection_ni_ni.stream_ni_ni.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_map_ni_ni_first(
                    (const struct butterflyfish_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
}

static void
check_as_collection_first_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .collection_ni_ni.stream_ni_ni.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_ni_ni_first(
                    (const struct butterflyfish_collection_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_NI_NI_ERROR_COLLECTION_IS_EMPTY);
}

static void check_as_stream_first_error_on_stream_is_empty(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .collection_ni_ni.stream_ni_ni.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stream_ni_ni_first(
                    (const struct butterflyfish_stream_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_NI_NI_ERROR_STREAM_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_last(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_last((void *) 1, NULL),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_map_is_empty(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .collection_ni_ni.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_map_ni_ni_last(
                    (const struct butterflyfish_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
}

static void
check_as_collection_last_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .collection_ni_ni.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_ni_ni_last(
                    (const struct butterflyfish_collection_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_NI_NI_ERROR_COLLECTION_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_entry_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_ENTRY_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static int
np_emit_error(const void *const object,
              const struct butterflyfish_map_entry_ni_ni *const entry,
              const struct butterflyfish_map_entry_ni_ni **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(entry);
    assert_non_null(out);
    return mock();
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .collection_ni_ni.stream_ni_ni.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_map_ni_ni_next(
                    (const struct butterflyfish_map_ni_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .collection_ni_ni.stream_ni_ni.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_ni_ni_next(
                    (const struct butterflyfish_collection_ni_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_NI_NI_ERROR_END_OF_SEQUENCE);
}

static void check_as_stream_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .collection_ni_ni.stream_ni_ni.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stream_ni_ni_next(
                    (const struct butterflyfish_stream_ni_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_NI_NI_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_entry_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_ENTRY_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .collection_ni_ni.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_map_ni_ni_prev(
                    (const struct butterflyfish_map_ni_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .collection_ni_ni.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_ni_ni_prev(
                    (const struct butterflyfish_collection_ni_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_NI_NI_ERROR_END_OF_SEQUENCE);
}

static void check_remove_entry_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_remove_entry(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_remove_entry_error_on_entry_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_remove_entry((void *) 1, NULL),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_ENTRY_IS_NULL);
}

static void check_remove_all_entries_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_remove_all_entries(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_entries_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_remove_all_entries((void *) 1, NULL),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OTHER_IS_NULL);
}

static void check_add_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_add(NULL, 0, 0),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static int apr_emit_error(void *const object,
                          const uintmax_t key,
                          const uintmax_t value) {
    function_called();
    assert_non_null(object);
    return mock();
}

static void check_add_error_on_key_already_exists(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .add = apr_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_KEY_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_map_ni_ni_add(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_KEY_ALREADY_EXISTS);
}

static void check_add_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .add = apr_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_add(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_put_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_put(NULL, 0, 0),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_put_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .put = apr_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_put(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_replace_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_replace(NULL, 0, 0),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_replace_error_on_key_not_found(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .replace = apr_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_map_ni_ni_replace(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
}

static void check_replace_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .replace = apr_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_replace(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_remove(NULL, 0),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static int remove_emit_error(void *const object,
                             const uintmax_t key) {
    function_called();
    assert_non_null(object);
    return mock();
}

static void check_remove_error_on_key_not_found(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_map_ni_ni_remove(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    0),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
}

static void check_remove_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_remove(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    0),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_add_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_add_all(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_add_all_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_add_all((void *) 1, NULL),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OTHER_IS_NULL);
}

static int
all_emit_error(void *const object,
               const struct butterflyfish_stream_ni_ni *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static void check_add_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .add_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_add_all(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_put_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_put_all(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_put_all_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_put_all((void *) 1, NULL),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OTHER_IS_NULL);
}

static void check_put_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .put_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_put_all(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_replace_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_replace_all(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_replace_all_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_replace_all((void *) 1, NULL),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OTHER_IS_NULL);
}

static void check_replace_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .replace_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_replace_all(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_remove_all(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_remove_all((void *) 1, NULL),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OTHER_IS_NULL);
}

static int
rr_all_emit_error(void *const object,
                  const struct butterflyfish_stream_ni *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static void check_remove_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .remove_all = rr_all_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(rr_all_emit_error);
    will_return(rr_all_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_remove_all(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_retain_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_retain_all(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_retain_all_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_retain_all((void *) 1, NULL),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OTHER_IS_NULL);
}

static void check_retain_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .retain_all = rr_all_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(rr_all_emit_error);
    will_return(rr_all_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_retain_all(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_merge_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_merge(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_merge_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_merge((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OTHER_IS_NULL);
}

static void check_merge_error_on_function_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_merge((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_FUNCTION_IS_NULL);
}

static int
merge_emit_error(void *const object,
                 const struct butterflyfish_stream_ni_ni *const other,
                 int (*const function)(
                         const uintmax_t,
                         const uintmax_t,
                         uintmax_t *)) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    assert_non_null(function);
    return mock();
}

static void check_merge_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .merge = merge_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(merge_emit_error);
    will_return(merge_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_merge(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_key_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_contains_key(NULL, 0, (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_contains_key_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_contains_key((void *) 1, 0, NULL),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static int
contains_key_emit_error(const void *const object,
                        const uintmax_t key,
                        bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void
check_contains_key_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .contains_key = contains_key_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(contains_key_emit_error);
    will_return(contains_key_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_contains_key(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_all_keys_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_contains_all_keys(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_contains_all_keys_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_contains_all_keys(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OTHER_IS_NULL);
}

static void check_contains_all_keys_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_contains_all_keys(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static int
contains_all_keys_emit_error(const void *const object,
                             const struct butterflyfish_stream_ni *const other,
                             bool *out) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    assert_non_null(out);
    return mock();
}

static void
check_contains_all_keys_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .contains_all_keys = contains_all_keys_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(contains_all_keys_emit_error);
    will_return(contains_all_keys_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_contains_all_keys(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_get(NULL, 0, (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_get((void *) 1, 0, NULL),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static int get_emit_error(const void *const object,
                          const uintmax_t key,
                          const uintmax_t *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_get_error_on_key_not_found(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .get = get_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_map_ni_ni_get(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
}

static void check_get_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .get = get_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_get(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_entry_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_get_entry(NULL, 0, (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_get_entry_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_get_entry((void *) 1, 0, NULL),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static int
get_entry_emit_error(const void *const object,
                     const uintmax_t key,
                     const struct butterflyfish_map_entry_ni_ni **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_get_entry_error_on_key_not_found(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .get_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_map_ni_ni_get_entry(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
}

static void check_get_entry_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_map_ni_ni map_ni_ni = {
            .get_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_map_ni_ni *map_ni_ni;
    };
    struct object instance = {
            .map_ni_ni = &map_ni_ni
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_get_entry(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_keys_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_keys(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_keys_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_keys((void *) 1, NULL),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static void check_values_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_values(NULL, (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_values_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_map_ni_ni_values((void *) 1, NULL),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
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
            cmocka_unit_test(check_remove_all_entries_error_on_object_is_null),
            cmocka_unit_test(check_remove_all_entries_error_on_other_is_null),
            cmocka_unit_test(check_add_error_on_object_is_null),
            cmocka_unit_test(check_add_error_on_key_already_exists),
            cmocka_unit_test(check_add_error_on_memory_allocation_failed),
            cmocka_unit_test(check_put_error_on_object_is_null),
            cmocka_unit_test(check_put_error_on_memory_allocation_failed),
            cmocka_unit_test(check_replace_error_on_object_is_null),
            cmocka_unit_test(check_replace_error_on_key_not_found),
            cmocka_unit_test(check_replace_error_on_memory_allocation_failed),
            cmocka_unit_test(check_remove_error_on_object_is_null),
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
            cmocka_unit_test(check_contains_key_error_on_out_is_null),
            cmocka_unit_test(check_contains_key_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_all_keys_error_on_object_is_null),
            cmocka_unit_test(check_contains_all_keys_error_on_other_is_null),
            cmocka_unit_test(check_contains_all_keys_error_on_out_is_null),
            cmocka_unit_test(check_contains_all_keys_error_on_memory_allocation_failed),
            cmocka_unit_test(check_get_error_on_object_is_null),
            cmocka_unit_test(check_get_error_on_out_is_null),
            cmocka_unit_test(check_get_error_on_key_not_found),
            cmocka_unit_test(check_get_error_on_memory_allocation_failed),
            cmocka_unit_test(check_get_entry_error_on_object_is_null),
            cmocka_unit_test(check_get_entry_error_on_out_is_null),
            cmocka_unit_test(check_get_entry_error_on_key_not_found),
            cmocka_unit_test(check_get_entry_error_on_memory_allocation_failed),
            cmocka_unit_test(check_keys_error_on_object_is_null),
            cmocka_unit_test(check_keys_error_on_out_is_null),
            cmocka_unit_test(check_values_error_on_object_is_null),
            cmocka_unit_test(check_values_error_on_out_is_null),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
