#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_count(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_count((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_first(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_first((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL);
}

static int
fl_emit_error(const void *const object,
              struct butterflyfish_map_entry_p_p **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_first_error_on_map_is_empty(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.collection_p_p.stream_p_p.first
            = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_first(
                    (const struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MAP_IS_EMPTY);
}

static void check_as_ordered_map_first_error_on_map_is_empty(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.collection_p_p.stream_p_p.first
            = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_ordered_map_p_p_first(
                    (const struct butterflyfish_ordered_map_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_P_P_ERROR_MAP_IS_EMPTY);
}

static void check_as_map_first_error_on_map_is_empty(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.collection_p_p.stream_p_p.first
            = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_map_p_p_first(
                    (const struct butterflyfish_map_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_P_P_ERROR_MAP_IS_EMPTY);
}

static void
check_as_collection_first_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.collection_p_p.stream_p_p.first
            = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_p_p_first(
                    (const struct butterflyfish_collection_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_P_P_ERROR_COLLECTION_IS_EMPTY);
}

static void check_as_stream_first_error_on_stream_is_empty(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.collection_p_p.stream_p_p.first
            = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stream_p_p_first(
                    (const struct butterflyfish_stream_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_P_P_ERROR_STREAM_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_last(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_last((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_map_is_empty(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.collection_p_p.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_last(
                    (const struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MAP_IS_EMPTY);
}

static void check_as_ordered_map_last_error_on_map_is_empty(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.collection_p_p.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_ordered_map_p_p_last(
                    (const struct butterflyfish_ordered_map_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_P_P_ERROR_MAP_IS_EMPTY);
}

static void check_as_map_last_error_on_map_is_empty(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.collection_p_p.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_map_p_p_last(
                    (const struct butterflyfish_map_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_P_P_ERROR_MAP_IS_EMPTY);
}

static void
check_as_collection_last_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.collection_p_p.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_p_p_last(
                    (const struct butterflyfish_collection_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_P_P_ERROR_COLLECTION_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_entry_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_ENTRY_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL);
}

static int
np_emit_error(const void *const object,
              const struct butterflyfish_map_entry_p_p *const entry,
              struct butterflyfish_map_entry_p_p **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(entry);
    assert_non_null(out);
    return mock();
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.collection_p_p.stream_p_p.next
            = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_next(
                    (const struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_END_OF_SEQUENCE);
}

static void check_as_ordered_map_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.collection_p_p.stream_p_p.next
            = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_ordered_map_p_p_next(
                    (const struct butterflyfish_ordered_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_P_P_ERROR_END_OF_SEQUENCE);
}

static void check_as_map_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.collection_p_p.stream_p_p.next
            = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_map_p_p_next(
                    (const struct butterflyfish_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_P_P_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.collection_p_p.stream_p_p.next
            = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_p_p_next(
                    (const struct butterflyfish_collection_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_P_P_ERROR_END_OF_SEQUENCE);
}

static void check_as_stream_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.collection_p_p.stream_p_p.next
            = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stream_p_p_next(
                    (const struct butterflyfish_stream_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_P_P_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_entry_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_ENTRY_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.collection_p_p.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_prev(
                    (const struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_END_OF_SEQUENCE);
}

static void check_as_ordered_map_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.collection_p_p.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_ordered_map_p_p_prev(
                    (const struct butterflyfish_ordered_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_P_P_ERROR_END_OF_SEQUENCE);
}

static void check_as_map_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.collection_p_p.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_map_p_p_prev(
                    (const struct butterflyfish_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_P_P_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.collection_p_p.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_p_p_prev(
                    (const struct butterflyfish_collection_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_P_P_ERROR_END_OF_SEQUENCE);
}

static void check_remove_entry_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_remove_entry(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_remove_entry_error_on_entry_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_remove_entry((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_ENTRY_IS_NULL);
}

static void check_remove_all_entries_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_remove_all_entries(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_entries_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_remove_all_entries((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OTHER_IS_NULL);
}

static void check_add_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_add(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_add_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_add((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_IS_NULL);
}

static void check_add_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_add((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_VALUE_IS_NULL);
}

static int apr_emit_error(void *const object,
                          const void *const key,
                          const void *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(key);
    assert_non_null(value);
    return mock();
}

static void check_add_error_on_key_already_exists(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.add = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_add(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_ALREADY_EXISTS);
}

static void
check_as_ordered_map_add_error_on_key_already_exists(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.add = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_ordered_map_p_p_add(
                    (struct butterflyfish_ordered_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_P_P_ERROR_KEY_ALREADY_EXISTS);
}

static void check_as_map_add_error_on_key_already_exists(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.add = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_map_p_p_add(
                    (struct butterflyfish_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_P_P_ERROR_KEY_ALREADY_EXISTS);
}

static void check_add_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.add = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_add(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_add_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.add = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_p_p_add(
                    (struct butterflyfish_ordered_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_as_map_add_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.add = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_p_p_add(
                    (struct butterflyfish_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_put_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_put(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_put_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_put((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_IS_NULL);
}

static void check_put_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_put((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_VALUE_IS_NULL);
}

static void check_put_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.put = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_put(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_put_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.put = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_p_p_put(
                    (struct butterflyfish_ordered_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_as_map_put_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.put = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_p_p_put(
                    (struct butterflyfish_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_replace_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_replace(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_replace_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_replace((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_IS_NULL);
}

static void check_replace_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_replace((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_VALUE_IS_NULL);
}

static void check_replace_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.replace = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_replace(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
}

static void
check_as_ordered_map_replace_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.replace = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_ordered_map_p_p_replace(
                    (struct butterflyfish_ordered_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_P_P_ERROR_KEY_NOT_FOUND);
}

static void check_as_map_replace_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.replace = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_map_p_p_replace(
                    (struct butterflyfish_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_P_P_ERROR_KEY_NOT_FOUND);
}

static void check_replace_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.replace = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_replace(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_ordered_map_replace_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.replace = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_p_p_replace(
                    (struct butterflyfish_ordered_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_replace_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.replace = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_p_p_replace(
                    (struct butterflyfish_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_remove(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_remove_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_remove((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_IS_NULL);
}

static int remove_emit_error(void *const object,
                             const void *const key) {
    function_called();
    assert_non_null(object);
    assert_non_null(key);
    return mock();
}

static void check_remove_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_remove(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_remove_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_p_p_remove(
                    (struct butterflyfish_ordered_map_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_remove_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_p_p_remove(
                    (struct butterflyfish_map_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_add_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_add_all(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_add_all_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_add_all((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OTHER_IS_NULL);
}

static int
all_emit_error(void *const object,
               const struct butterflyfish_stream_p_p *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static void check_add_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.add_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_add_all(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_add_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.add_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_p_p_add_all(
                    (struct butterflyfish_ordered_map_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_add_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.add_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_p_p_add_all(
                    (struct butterflyfish_map_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_put_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_put_all(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_put_all_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_put_all((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OTHER_IS_NULL);
}

static void check_put_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.put_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_put_all(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_put_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.put_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_p_p_put_all(
                    (struct butterflyfish_ordered_map_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_put_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.put_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_p_p_put_all(
                    (struct butterflyfish_map_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_replace_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_replace_all(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_replace_all_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_replace_all((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OTHER_IS_NULL);
}

static void check_replace_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.replace_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_replace_all(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_replace_all_error_on_memory_allocation_failed(
        void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.replace_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_p_p_replace_all(
                    (struct butterflyfish_ordered_map_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_replace_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.replace_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_p_p_replace_all(
                    (struct butterflyfish_map_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_remove_all(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_remove_all((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OTHER_IS_NULL);
}

static int
rr_all_emit_error(void *const object,
                  const struct butterflyfish_stream_p *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static void check_remove_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.remove_all = rr_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(rr_all_emit_error);
    will_return(rr_all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_remove_all(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_remove_all_error_on_memory_allocation_failed(
        void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.remove_all = rr_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(rr_all_emit_error);
    will_return(rr_all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_p_p_remove_all(
                    (struct butterflyfish_ordered_map_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_remove_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.remove_all = rr_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(rr_all_emit_error);
    will_return(rr_all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_p_p_remove_all(
                    (struct butterflyfish_map_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_retain_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_retain_all(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_retain_all_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_retain_all((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OTHER_IS_NULL);
}

static void check_retain_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.retain_all = rr_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(rr_all_emit_error);
    will_return(rr_all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_retain_all(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_retain_all_error_on_memory_allocation_failed(
        void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.retain_all = rr_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(rr_all_emit_error);
    will_return(rr_all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_p_p_retain_all(
                    (struct butterflyfish_ordered_map_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_retain_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.retain_all = rr_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(rr_all_emit_error);
    will_return(rr_all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_p_p_retain_all(
                    (struct butterflyfish_map_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_merge_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_merge(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_merge_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_merge((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OTHER_IS_NULL);
}

static void check_merge_error_on_function_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_merge((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_FUNCTION_IS_NULL);
}

static int
merge_emit_error(void *const object,
                 const struct butterflyfish_stream_p_p *const other,
                 int (*const function)(
                         const void *,
                         const void *,
                         void **)) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    assert_non_null(function);
    return mock();
}

static void check_merge_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.merge = merge_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(merge_emit_error);
    will_return(merge_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_merge(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_merge_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.merge = merge_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(merge_emit_error);
    will_return(merge_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_p_p_merge(
                    (struct butterflyfish_ordered_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_merge_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.merge = merge_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(merge_emit_error);
    will_return(merge_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_p_p_merge(
                    (struct butterflyfish_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_key_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_contains_key(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_contains_key_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_contains_key((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_IS_NULL);
}

static void check_contains_key_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_contains_key((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL);
}

static int
contains_key_emit_error(const void *const object,
                        const void *const key,
                        bool *out) {
    function_called();
    assert_non_null(object);
    assert_non_null(key);
    assert_non_null(out);
    return mock();
}

static void
check_contains_key_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.contains_key = contains_key_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(contains_key_emit_error);
    will_return(contains_key_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_contains_key(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_contains_key_error_on_memory_allocation_failed(
        void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.contains_key = contains_key_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(contains_key_emit_error);
    will_return(contains_key_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_p_p_contains_key(
                    (struct butterflyfish_ordered_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_contains_key_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.contains_key = contains_key_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(contains_key_emit_error);
    will_return(contains_key_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_p_p_contains_key(
                    (struct butterflyfish_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_all_keys_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_contains_all_keys(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_contains_all_keys_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_contains_all_keys(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OTHER_IS_NULL);
}

static void check_contains_all_keys_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_contains_all_keys(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL);
}

static int
contains_all_keys_emit_error(const void *const object,
                             const struct butterflyfish_stream_p *const other,
                             bool *out) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    assert_non_null(out);
    return mock();
}

static void
check_contains_all_keys_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.contains_all_keys
            = contains_all_keys_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(contains_all_keys_emit_error);
    will_return(contains_all_keys_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_contains_all_keys(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_contains_all_keys_error_on_memory_allocation_failed(
        void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.contains_all_keys
            = contains_all_keys_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(contains_all_keys_emit_error);
    will_return(contains_all_keys_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_p_p_contains_all_keys(
                    (struct butterflyfish_ordered_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_contains_all_keys_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.contains_all_keys
            = contains_all_keys_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(contains_all_keys_emit_error);
    will_return(contains_all_keys_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_p_p_contains_all_keys(
                    (struct butterflyfish_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_get(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_get((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_get((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL);
}

static int get_emit_error(const void *const object,
                          const void *const key,
                          const void **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(key);
    assert_non_null(out);
    return mock();
}

static void check_get_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_get(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
}

static void check_as_ordered_map_get_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_ordered_map_p_p_get(
                    (struct butterflyfish_ordered_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_P_P_ERROR_KEY_NOT_FOUND);
}

static void check_as_map_get_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_map_p_p_get(
                    (struct butterflyfish_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_P_P_ERROR_KEY_NOT_FOUND);
}

static void check_get_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_get(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_get_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_p_p_get(
                    (struct butterflyfish_ordered_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_get_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_p_p_get(
                    (struct butterflyfish_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_entry_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_get_entry(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_get_entry_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_get_entry((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_IS_NULL);
}

static void check_get_entry_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_get_entry((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL);
}

static int
get_entry_emit_error(const void *const object,
                     const void *const key,
                     struct butterflyfish_map_entry_p_p **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(key);
    assert_non_null(out);
    return mock();
}

static void check_get_entry_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.get_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_get_entry(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
}

static void
check_as_ordered_map_get_entry_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.get_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_ordered_map_p_p_get_entry(
                    (struct butterflyfish_ordered_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_P_P_ERROR_KEY_NOT_FOUND);
}

static void check_as_map_get_entry_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.get_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_map_p_p_get_entry(
                    (struct butterflyfish_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_P_P_ERROR_KEY_NOT_FOUND);
}

static void check_get_entry_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.get_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_get_entry(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_get_entry_error_on_memory_allocation_failed(
        void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.get_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_p_p_get_entry(
                    (struct butterflyfish_ordered_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_get_entry_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ordered_map_p_p.map_p_p.get_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_p_p_get_entry(
                    (struct butterflyfish_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_keys_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_keys(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_keys_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_keys((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL);
}

static void check_values_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_values(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_values_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_values((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL);
}

static void check_ceiling_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_ceiling(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_ceiling_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_ceiling((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_IS_NULL);
}

static void check_ceiling_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_ceiling((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL);
}

static void check_ceiling_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ceiling = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_ceiling(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
}

static void check_ceiling_error_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ceiling = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_ceiling(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_floor_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_floor(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_floor_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_floor((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_IS_NULL);
}

static void check_floor_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_floor((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL);
}

static void check_floor_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .floor = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_floor(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
}

static void check_floor_error_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .floor = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_floor(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_higher_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_higher(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_higher_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_higher((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_IS_NULL);
}

static void check_higher_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_higher((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL);
}

static void check_higher_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .higher = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_higher(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
}

static void check_higher_error_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .higher = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_higher(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_lower_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_lower(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_lower_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_lower((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_IS_NULL);
}

static void check_lower_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_lower((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL);
}

static void check_lower_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .lower = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_lower(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
}

static void check_lower_error_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .lower = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_lower(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_ceiling_entry_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_ceiling_entry(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_ceiling_entry_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_ceiling_entry(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_IS_NULL);
}

static void check_ceiling_entry_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_ceiling_entry(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL);
}

static void check_ceiling_entry_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ceiling_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_ceiling_entry(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
}

static void check_ceiling_entry_error_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .ceiling_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_ceiling_entry(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_floor_entry_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_floor_entry(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_floor_entry_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_floor_entry(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_IS_NULL);
}

static void check_floor_entry_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_floor_entry(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL);
}

static void check_floor_entry_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .floor_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_floor_entry(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
}

static void check_floor_entry_error_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .floor_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_floor_entry(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_higher_entry_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_higher_entry(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_higher_entry_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_higher_entry(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_IS_NULL);
}

static void check_higher_entry_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_higher_entry(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL);
}

static void check_higher_entry_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .higher_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_higher_entry(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
}

static void check_higher_entry_error_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .higher_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_higher_entry(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_lower_entry_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_lower_entry(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_lower_entry_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_lower_entry(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_IS_NULL);
}

static void check_lower_entry_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_p_p_lower_entry(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL);
}

static void check_lower_entry_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .lower_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_lower_entry(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_KEY_NOT_FOUND);
}

static void check_lower_entry_error_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_p_p sorted_map_p_p = {
            .lower_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_p_p *sorted_map_p_p;
    };
    struct object instance = {
            .sorted_map_p_p = &sorted_map_p_p
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_p_p_lower_entry(
                    (struct butterflyfish_sorted_map_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_map_is_empty),
            cmocka_unit_test(check_as_ordered_map_first_error_on_map_is_empty),
            cmocka_unit_test(check_as_map_first_error_on_map_is_empty),
            cmocka_unit_test(check_as_collection_first_error_on_collection_is_empty),
            cmocka_unit_test(check_as_stream_first_error_on_stream_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_map_is_empty),
            cmocka_unit_test(check_as_ordered_map_last_error_on_map_is_empty),
            cmocka_unit_test(check_as_map_last_error_on_map_is_empty),
            cmocka_unit_test(check_as_collection_last_error_on_collection_is_empty),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_entry_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_ordered_map_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_map_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_collection_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_stream_next_error_on_end_of_sequence),
            cmocka_unit_test(check_prev_error_on_object_is_null),
            cmocka_unit_test(check_prev_error_on_entry_is_null),
            cmocka_unit_test(check_prev_error_on_out_is_null),
            cmocka_unit_test(check_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_as_ordered_map_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_as_map_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_as_collection_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_remove_entry_error_on_object_is_null),
            cmocka_unit_test(check_remove_entry_error_on_entry_is_null),
            cmocka_unit_test(check_remove_all_entries_error_on_object_is_null),
            cmocka_unit_test(check_remove_all_entries_error_on_other_is_null),
            cmocka_unit_test(check_add_error_on_object_is_null),
            cmocka_unit_test(check_add_error_on_key_is_null),
            cmocka_unit_test(check_add_error_on_value_is_null),
            cmocka_unit_test(check_add_error_on_key_already_exists),
            cmocka_unit_test(check_as_ordered_map_add_error_on_key_already_exists),
            cmocka_unit_test(check_as_map_add_error_on_key_already_exists),
            cmocka_unit_test(check_add_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_add_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_add_error_on_memory_allocation_failed),
            cmocka_unit_test(check_put_error_on_object_is_null),
            cmocka_unit_test(check_put_error_on_key_is_null),
            cmocka_unit_test(check_put_error_on_value_is_null),
            cmocka_unit_test(check_put_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_put_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_put_error_on_memory_allocation_failed),
            cmocka_unit_test(check_replace_error_on_object_is_null),
            cmocka_unit_test(check_replace_error_on_key_is_null),
            cmocka_unit_test(check_replace_error_on_value_is_null),
            cmocka_unit_test(check_replace_error_on_key_not_found),
            cmocka_unit_test(check_as_ordered_map_replace_error_on_key_not_found),
            cmocka_unit_test(check_as_map_replace_error_on_key_not_found),
            cmocka_unit_test(check_ordered_map_replace_error_on_memory_allocation_failed),
            cmocka_unit_test(check_replace_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_replace_error_on_memory_allocation_failed),
            cmocka_unit_test(check_remove_error_on_object_is_null),
            cmocka_unit_test(check_remove_error_on_key_is_null),
            cmocka_unit_test(check_remove_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_remove_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_remove_error_on_memory_allocation_failed),
            cmocka_unit_test(check_add_all_error_on_object_is_null),
            cmocka_unit_test(check_add_all_error_on_key_is_null),
            cmocka_unit_test(check_add_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_add_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_add_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_put_all_error_on_object_is_null),
            cmocka_unit_test(check_put_all_error_on_key_is_null),
            cmocka_unit_test(check_put_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_put_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_put_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_replace_all_error_on_object_is_null),
            cmocka_unit_test(check_replace_all_error_on_key_is_null),
            cmocka_unit_test(check_replace_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_replace_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_replace_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_remove_all_error_on_object_is_null),
            cmocka_unit_test(check_remove_all_error_on_key_is_null),
            cmocka_unit_test(check_remove_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_remove_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_remove_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_retain_all_error_on_object_is_null),
            cmocka_unit_test(check_retain_all_error_on_key_is_null),
            cmocka_unit_test(check_retain_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_retain_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_retain_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_merge_error_on_object_is_null),
            cmocka_unit_test(check_merge_error_on_other_is_null),
            cmocka_unit_test(check_merge_error_on_function_is_null),
            cmocka_unit_test(check_merge_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_merge_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_merge_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_key_error_on_object_is_null),
            cmocka_unit_test(check_contains_key_error_on_other_is_null),
            cmocka_unit_test(check_contains_key_error_on_out_is_null),
            cmocka_unit_test(check_contains_key_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_contains_key_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_contains_key_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_all_keys_error_on_object_is_null),
            cmocka_unit_test(check_contains_all_keys_error_on_other_is_null),
            cmocka_unit_test(check_contains_all_keys_error_on_out_is_null),
            cmocka_unit_test(check_contains_all_keys_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_contains_all_keys_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_contains_all_keys_error_on_memory_allocation_failed),
            cmocka_unit_test(check_get_error_on_object_is_null),
            cmocka_unit_test(check_get_error_on_key_is_null),
            cmocka_unit_test(check_get_error_on_out_is_null),
            cmocka_unit_test(check_get_error_on_key_not_found),
            cmocka_unit_test(check_as_ordered_map_get_error_on_key_not_found),
            cmocka_unit_test(check_as_map_get_error_on_key_not_found),
            cmocka_unit_test(check_get_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_get_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_get_error_on_memory_allocation_failed),
            cmocka_unit_test(check_get_entry_error_on_object_is_null),
            cmocka_unit_test(check_get_entry_error_on_key_is_null),
            cmocka_unit_test(check_get_entry_error_on_out_is_null),
            cmocka_unit_test(check_get_entry_error_on_key_not_found),
            cmocka_unit_test(check_as_ordered_map_get_entry_error_on_key_not_found),
            cmocka_unit_test(check_as_map_get_entry_error_on_key_not_found),
            cmocka_unit_test(check_get_entry_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_get_entry_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_get_entry_error_on_memory_allocation_failed),
            cmocka_unit_test(check_keys_error_on_object_is_null),
            cmocka_unit_test(check_keys_error_on_out_is_null),
            cmocka_unit_test(check_values_error_on_object_is_null),
            cmocka_unit_test(check_values_error_on_out_is_null),
            cmocka_unit_test(check_ceiling_error_on_object_is_null),
            cmocka_unit_test(check_ceiling_error_on_key_is_null),
            cmocka_unit_test(check_ceiling_error_on_out_is_null),
            cmocka_unit_test(check_ceiling_error_on_key_not_found),
            cmocka_unit_test(check_ceiling_error_memory_allocation_failed),
            cmocka_unit_test(check_floor_error_on_object_is_null),
            cmocka_unit_test(check_floor_error_on_key_is_null),
            cmocka_unit_test(check_floor_error_on_out_is_null),
            cmocka_unit_test(check_floor_error_on_key_not_found),
            cmocka_unit_test(check_floor_error_memory_allocation_failed),
            cmocka_unit_test(check_higher_error_on_object_is_null),
            cmocka_unit_test(check_higher_error_on_key_is_null),
            cmocka_unit_test(check_higher_error_on_out_is_null),
            cmocka_unit_test(check_higher_error_on_key_not_found),
            cmocka_unit_test(check_higher_error_memory_allocation_failed),
            cmocka_unit_test(check_lower_error_on_object_is_null),
            cmocka_unit_test(check_lower_error_on_key_is_null),
            cmocka_unit_test(check_lower_error_on_out_is_null),
            cmocka_unit_test(check_lower_error_on_key_not_found),
            cmocka_unit_test(check_lower_error_memory_allocation_failed),
            cmocka_unit_test(check_ceiling_entry_error_on_object_is_null),
            cmocka_unit_test(check_ceiling_entry_error_on_key_is_null),
            cmocka_unit_test(check_ceiling_entry_error_on_out_is_null),
            cmocka_unit_test(check_ceiling_entry_error_on_key_not_found),
            cmocka_unit_test(check_ceiling_entry_error_memory_allocation_failed),
            cmocka_unit_test(check_floor_entry_error_on_object_is_null),
            cmocka_unit_test(check_floor_entry_error_on_key_is_null),
            cmocka_unit_test(check_floor_entry_error_on_out_is_null),
            cmocka_unit_test(check_floor_entry_error_on_key_not_found),
            cmocka_unit_test(check_floor_entry_error_memory_allocation_failed),
            cmocka_unit_test(check_higher_entry_error_on_object_is_null),
            cmocka_unit_test(check_higher_entry_error_on_key_is_null),
            cmocka_unit_test(check_higher_entry_error_on_out_is_null),
            cmocka_unit_test(check_higher_entry_error_on_key_not_found),
            cmocka_unit_test(check_higher_entry_error_memory_allocation_failed),
            cmocka_unit_test(check_lower_entry_error_on_object_is_null),
            cmocka_unit_test(check_lower_entry_error_on_key_is_null),
            cmocka_unit_test(check_lower_entry_error_on_out_is_null),
            cmocka_unit_test(check_lower_entry_error_on_key_not_found),
            cmocka_unit_test(check_lower_entry_error_memory_allocation_failed),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
