#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_p_count(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_p_count((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OUT_IS_NULL);
}

static int fl_emit_error(const void *const object,
                         const void **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_first_error_on_reducible_list_is_empty(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.collection_p.stream_p.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_LIST_IS_EMPTY);
    assert_int_equal(
            butterflyfish_reducible_list_p_first(
                    (const struct butterflyfish_reducible_list_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_LIST_IS_EMPTY);
}

static void
check_as_fixed_list_first_error_on_fixed_list_is_empty(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.collection_p.stream_p.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_LIST_IS_EMPTY);
    assert_int_equal(
            butterflyfish_fixed_list_p_first(
                    (const struct butterflyfish_fixed_list_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_P_ERROR_LIST_IS_EMPTY);
}

static void
check_as_collection_first_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.collection_p.stream_p.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_LIST_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_p_first(
                    (const struct butterflyfish_collection_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_P_ERROR_COLLECTION_IS_EMPTY);
}

static void check_as_stream_first_error_on_stream_is_empty(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.collection_p.stream_p.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_LIST_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stream_p_first(
                    (const struct butterflyfish_stream_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_P_ERROR_STREAM_IS_EMPTY);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_p_first(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_p_first((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_p_last(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_p_last((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_reducible_list_is_empty(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.collection_p.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_LIST_IS_EMPTY);
    assert_int_equal(
            butterflyfish_reducible_list_p_last(
                    (const struct butterflyfish_reducible_list_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_LIST_IS_EMPTY);
}

static void
check_as_fixed_list_last_error_on_fixed_list_is_empty(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.collection_p.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_LIST_IS_EMPTY);
    assert_int_equal(
            butterflyfish_fixed_list_p_last(
                    (const struct butterflyfish_fixed_list_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_P_ERROR_LIST_IS_EMPTY);
}

static void
check_as_collection_last_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.collection_p.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_LIST_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_p_last(
                    (const struct butterflyfish_collection_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_P_ERROR_COLLECTION_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_p_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_p_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_p_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OUT_IS_NULL);
}

static int np_emit_error(const void *const object,
                         const void *const item,
                         const void **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.collection_p.stream_p.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_reducible_list_p_next(
                    (const struct butterflyfish_reducible_list_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_END_OF_SEQUENCE);
}

static void check_as_fixed_list_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.collection_p.stream_p.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_fixed_list_p_next(
                    (const struct butterflyfish_fixed_list_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_P_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.collection_p.stream_p.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_p_next(
                    (const struct butterflyfish_collection_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_P_ERROR_END_OF_SEQUENCE);
}

static void check_as_stream_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.collection_p.stream_p.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stream_p_next(
                    (const struct butterflyfish_stream_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_P_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_p_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_p_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_p_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.collection_p.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_reducible_list_p_prev(
                    (const struct butterflyfish_reducible_list_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_END_OF_SEQUENCE);
}

static void check_as_fixed_list_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.collection_p.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_fixed_list_p_prev(
                    (const struct butterflyfish_fixed_list_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_P_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.collection_p.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_p_prev(
                    (const struct butterflyfish_collection_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_P_ERROR_END_OF_SEQUENCE);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_p_get(NULL, 0, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_out(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_p_get((void *) 1, 0, NULL),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OUT_IS_NULL);
}

static int get_emit_error(const void *const object,
                          const uintmax_t at,
                          const void **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_get_error_on_index_out_of_bounds(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_INDEX_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_reducible_list_p_get(
                    (const struct butterflyfish_reducible_list_p *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_INDEX_IS_OUT_OF_BOUNDS);
}

static void
check_as_fixed_list_get_error_on_index_out_of_bounds(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_INDEX_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_fixed_list_p_get(
                    (const struct butterflyfish_fixed_list_p *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_P_ERROR_INDEX_IS_OUT_OF_BOUNDS);
}

static void check_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_p_set(NULL, 0, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OBJECT_IS_NULL);
}

static int set_emit_error(void *const object,
                          const uintmax_t at,
                          const void *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    return mock();
}

static void check_set_error_on_index_out_of_bounds(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.set = set_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(set_emit_error);
    will_return(set_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_INDEX_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_reducible_list_p_set(
                    (struct butterflyfish_reducible_list_p *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_INDEX_IS_OUT_OF_BOUNDS);
}

static void
check_as_fixed_list_set_error_on_index_out_of_bounds(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.set = set_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(set_emit_error);
    will_return(set_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_INDEX_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_fixed_list_p_set(
                    (struct butterflyfish_fixed_list_p *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_P_ERROR_INDEX_IS_OUT_OF_BOUNDS);
}

static void check_set_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.set = set_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(set_emit_error);
    will_return(set_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_reducible_list_p_set(
                    (struct butterflyfish_reducible_list_p *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_fixed_list_set_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.set = set_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(set_emit_error);
    will_return(set_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_fixed_list_p_set(
                    (struct butterflyfish_fixed_list_p *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_set_error_on_value_is_invalid(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.set = set_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(set_emit_error);
    will_return(set_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_reducible_list_p_set(
                    (struct butterflyfish_reducible_list_p *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_VALUE_IS_INVALID);
}

static void
check_as_fixed_list_set_error_on_value_is_invalid(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.set = set_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(set_emit_error);
    will_return(set_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_fixed_list_p_set(
                    (struct butterflyfish_fixed_list_p *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_P_ERROR_VALUE_IS_INVALID);
}

static void check_set_item_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_p_set_item(
                    NULL, (void *) 1, 0),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OBJECT_IS_NULL);
}

static void check_set_item_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_p_set_item(
                    (void *) 1, NULL, 0),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_ITEM_IS_NULL);
}

static int set_item_emit_error(void *const object,
                               void *const item,
                               const void *value) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    return mock();
}

static void check_set_item_error_on_item_is_out_of_bounds(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.set_item = set_item_emit_error,
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(set_item_emit_error);
    will_return(set_item_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_ITEM_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_reducible_list_p_set_item(
                    (struct butterflyfish_reducible_list_p *) &instance,
                    (void *) 1,
                    0),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_ITEM_IS_OUT_OF_BOUNDS);
}

static void
check_set_item_as_fixed_list_error_on_item_is_out_of_bounds(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.set_item = set_item_emit_error,
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(set_item_emit_error);
    will_return(set_item_emit_error,
                BUTTERFLYFISH_FIXED_LIST_P_ERROR_ITEM_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_fixed_list_p_set_item(
                    (struct butterflyfish_fixed_list_p *) &instance,
                    (void *) 1,
                    0),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_ITEM_IS_OUT_OF_BOUNDS);
}

static void check_set_item_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.set_item = set_item_emit_error,
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(set_item_emit_error);
    will_return(set_item_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_reducible_list_p_set_item(
                    (struct butterflyfish_reducible_list_p *) &instance,
                    (void *) 1,
                    0),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_set_item_as_fixed_list_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.set_item = set_item_emit_error,
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(set_item_emit_error);
    will_return(set_item_emit_error,
                BUTTERFLYFISH_FIXED_LIST_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_fixed_list_p_set_item(
                    (struct butterflyfish_fixed_list_p *) &instance,
                    (void *) 1,
                    0),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_set_item_error_on_value_is_invalid(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.set_item = set_item_emit_error,
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(set_item_emit_error);
    will_return(set_item_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_reducible_list_p_set_item(
                    (struct butterflyfish_reducible_list_p *) &instance,
                    (void *) 1,
                    0),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_VALUE_IS_INVALID);
}

static void
check_set_item_as_fixed_list_error_on_value_is_invalid(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.set_item = set_item_emit_error,
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(set_item_emit_error);
    will_return(set_item_emit_error,
                BUTTERFLYFISH_FIXED_LIST_P_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_fixed_list_p_set_item(
                    (struct butterflyfish_fixed_list_p *) &instance,
                    (void *) 1,
                    0),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_VALUE_IS_INVALID);
}

static void check_at_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_p_at(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OBJECT_IS_NULL);
}

static void check_at_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_p_at((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_ITEM_IS_NULL);
}

static void check_at_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_p_at((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OUT_IS_NULL);
}

static int at_emit_error(const void *const object,
                         const void *const item,
                         uintmax_t *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

static void check_at_error_on_item_is_out_of_bounds(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.at = at_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(at_emit_error);
    will_return(at_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_ITEM_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_reducible_list_p_at(
                    (struct butterflyfish_reducible_list_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_ITEM_IS_OUT_OF_BOUNDS);
}

static void
check_as_fixed_list_at_error_on_item_is_out_of_bounds(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .fixed_list_p.at = at_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(at_emit_error);
    will_return(at_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_ITEM_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_fixed_list_p_at(
                    (struct butterflyfish_fixed_list_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_P_ERROR_ITEM_IS_OUT_OF_BOUNDS);
}

static void check_remove_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_p_remove(NULL, 0),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OBJECT_IS_NULL);
}

static int remove_emit_error(void *const object,
                             const uintmax_t at) {
    function_called();
    assert_non_null(object);
    return mock();
}

static void check_remove_error_on_index_out_of_bounds(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_INDEX_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_reducible_list_p_remove(
                    (struct butterflyfish_reducible_list_p *) &instance,
                    0),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_INDEX_IS_OUT_OF_BOUNDS);
}

static void check_remove_item_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_p_remove_item(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OBJECT_IS_NULL);
}

static void check_remove_item_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_p_remove_item((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_ITEM_IS_NULL);
}

static int remove_item_emit_error(void *const object,
                                  const void *const item) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    return mock();
}

static void check_remove_item_error_on_item_out_of_bounds(void **state) {
    const struct butterflyfish_reducible_list_p reducible_list_p = {
            .remove_item = remove_item_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_p *reducible_list_p;
    };
    struct object instance = {
            .reducible_list_p = &reducible_list_p
    };
    expect_function_call(remove_item_emit_error);
    will_return(remove_item_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_ITEM_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_reducible_list_p_remove_item(
                    (struct butterflyfish_reducible_list_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_ITEM_IS_OUT_OF_BOUNDS);
}

static void check_remove_items_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_p_remove_all_items(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OBJECT_IS_NULL);
}

static void check_remove_items_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_p_remove_all_items((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OTHER_IS_NULL);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_reducible_list_is_empty),
            cmocka_unit_test(check_as_fixed_list_first_error_on_fixed_list_is_empty),
            cmocka_unit_test(check_as_collection_first_error_on_collection_is_empty),
            cmocka_unit_test(check_as_stream_first_error_on_stream_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_reducible_list_is_empty),
            cmocka_unit_test(check_as_fixed_list_last_error_on_fixed_list_is_empty),
            cmocka_unit_test(check_as_collection_last_error_on_collection_is_empty),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_item_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_fixed_list_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_collection_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_stream_next_error_on_end_of_sequence),
            cmocka_unit_test(check_prev_error_on_object_is_null),
            cmocka_unit_test(check_prev_error_on_item_is_null),
            cmocka_unit_test(check_prev_error_on_out_is_null),
            cmocka_unit_test(check_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_as_fixed_list_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_as_collection_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_get_error_on_object_is_null),
            cmocka_unit_test(check_get_error_on_out),
            cmocka_unit_test(check_get_error_on_index_out_of_bounds),
            cmocka_unit_test(check_as_fixed_list_get_error_on_index_out_of_bounds),
            cmocka_unit_test(check_set_error_on_object_is_null),
            cmocka_unit_test(check_set_error_on_index_out_of_bounds),
            cmocka_unit_test(check_as_fixed_list_set_error_on_index_out_of_bounds),
            cmocka_unit_test(check_set_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_fixed_list_set_error_on_memory_allocation_failed),
            cmocka_unit_test(check_set_error_on_value_is_invalid),
            cmocka_unit_test(check_as_fixed_list_set_error_on_value_is_invalid),
            cmocka_unit_test(check_set_item_error_on_object_is_null),
            cmocka_unit_test(check_set_item_error_on_item_is_null),
            cmocka_unit_test(check_set_item_error_on_item_is_out_of_bounds),
            cmocka_unit_test(check_set_item_as_fixed_list_error_on_item_is_out_of_bounds),
            cmocka_unit_test(check_set_item_error_on_memory_allocation_failed),
            cmocka_unit_test(check_set_item_as_fixed_list_error_on_memory_allocation_failed),
            cmocka_unit_test(check_set_item_error_on_value_is_invalid),
            cmocka_unit_test(check_set_item_as_fixed_list_error_on_value_is_invalid),
            cmocka_unit_test(check_at_error_on_object_is_null),
            cmocka_unit_test(check_at_error_on_item_is_null),
            cmocka_unit_test(check_at_error_on_out_is_null),
            cmocka_unit_test(check_at_error_on_item_is_out_of_bounds),
            cmocka_unit_test(check_as_fixed_list_at_error_on_item_is_out_of_bounds),
            cmocka_unit_test(check_remove_error_on_object_is_null),
            cmocka_unit_test(check_remove_error_on_index_out_of_bounds),
            cmocka_unit_test(check_remove_item_error_on_object_is_null),
            cmocka_unit_test(check_remove_item_error_on_item_is_null),
            cmocka_unit_test(check_remove_item_error_on_item_out_of_bounds),
            cmocka_unit_test(check_remove_items_error_on_object_is_null),
            cmocka_unit_test(check_remove_items_error_on_other_is_null),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
