#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_fixed_list_wr_count(NULL, (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_fixed_list_wr_count((void *) 1, NULL),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OUT_IS_NULL);
}

static int fl_emit_error(const void *const object,
                         const struct triggerfish_weak **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_first_error_on_fixed_list_is_empty(void **state) {
    const struct butterflyfish_fixed_list_wr fixed_list_wr = {
            .collection_wr.stream_wr.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_fixed_list_wr *fixed_list_wr;
    };
    struct object instance = {
            .fixed_list_wr = &fixed_list_wr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_FIXED_LIST_WR_ERROR_LIST_IS_EMPTY);
    assert_int_equal(
            butterflyfish_fixed_list_wr_first(
                    (const struct butterflyfish_fixed_list_wr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_LIST_IS_EMPTY);
}

static void
check_as_collection_first_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_fixed_list_wr fixed_list_wr = {
            .collection_wr.stream_wr.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_fixed_list_wr *fixed_list_wr;
    };
    struct object instance = {
            .fixed_list_wr = &fixed_list_wr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_FIXED_LIST_WR_ERROR_LIST_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_wr_first(
                    (const struct butterflyfish_collection_wr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_WR_ERROR_COLLECTION_IS_EMPTY);
}

static void check_as_stream_first_error_on_stream_is_empty(void **state) {
    const struct butterflyfish_fixed_list_wr fixed_list_wr = {
            .collection_wr.stream_wr.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_fixed_list_wr *fixed_list_wr;
    };
    struct object instance = {
            .fixed_list_wr = &fixed_list_wr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_FIXED_LIST_WR_ERROR_LIST_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stream_wr_first(
                    (const struct butterflyfish_stream_wr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_WR_ERROR_STREAM_IS_EMPTY);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_fixed_list_wr_first(NULL, (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_fixed_list_wr_first((void *) 1, NULL),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_fixed_list_wr_last(NULL, (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_fixed_list_wr_last((void *) 1, NULL),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_fixed_list_is_empty(void **state) {
    const struct butterflyfish_fixed_list_wr fixed_list_wr = {
            .collection_wr.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_fixed_list_wr *fixed_list_wr;
    };
    struct object instance = {
            .fixed_list_wr = &fixed_list_wr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_FIXED_LIST_WR_ERROR_LIST_IS_EMPTY);
    assert_int_equal(
            butterflyfish_fixed_list_wr_last(
                    (const struct butterflyfish_fixed_list_wr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_LIST_IS_EMPTY);
}

static void
check_as_collection_last_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_fixed_list_wr fixed_list_wr = {
            .collection_wr.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_fixed_list_wr *fixed_list_wr;
    };
    struct object instance = {
            .fixed_list_wr = &fixed_list_wr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_FIXED_LIST_WR_ERROR_LIST_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_wr_last(
                    (const struct butterflyfish_collection_wr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_WR_ERROR_COLLECTION_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_fixed_list_wr_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_fixed_list_wr_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_fixed_list_wr_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OUT_IS_NULL);
}

static int np_emit_error(const void *const object,
                         const struct triggerfish_weak *const item,
                         const struct triggerfish_weak **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_fixed_list_wr fixed_list_wr = {
            .collection_wr.stream_wr.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_fixed_list_wr *fixed_list_wr;
    };
    struct object instance = {
            .fixed_list_wr = &fixed_list_wr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_FIXED_LIST_WR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_fixed_list_wr_next(
                    (const struct butterflyfish_fixed_list_wr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_fixed_list_wr fixed_list_wr = {
            .collection_wr.stream_wr.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_fixed_list_wr *fixed_list_wr;
    };
    struct object instance = {
            .fixed_list_wr = &fixed_list_wr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_FIXED_LIST_WR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_wr_next(
                    (const struct butterflyfish_collection_wr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_WR_ERROR_END_OF_SEQUENCE);
}

static void check_as_stream_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_fixed_list_wr fixed_list_wr = {
            .collection_wr.stream_wr.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_fixed_list_wr *fixed_list_wr;
    };
    struct object instance = {
            .fixed_list_wr = &fixed_list_wr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_FIXED_LIST_WR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stream_wr_next(
                    (const struct butterflyfish_stream_wr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_WR_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_fixed_list_wr_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_fixed_list_wr_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_fixed_list_wr_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_fixed_list_wr fixed_list_wr = {
            .collection_wr.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_fixed_list_wr *fixed_list_wr;
    };
    struct object instance = {
            .fixed_list_wr = &fixed_list_wr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_FIXED_LIST_WR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_fixed_list_wr_prev(
                    (const struct butterflyfish_fixed_list_wr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_fixed_list_wr fixed_list_wr = {
            .collection_wr.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_fixed_list_wr *fixed_list_wr;
    };
    struct object instance = {
            .fixed_list_wr = &fixed_list_wr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_FIXED_LIST_WR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_wr_prev(
                    (const struct butterflyfish_collection_wr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_WR_ERROR_END_OF_SEQUENCE);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_fixed_list_wr_get(NULL, 0, (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_out(void **state) {
    assert_int_equal(
            butterflyfish_fixed_list_wr_get((void *) 1, 0, NULL),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OUT_IS_NULL);
}

static int get_emit_error(const void *const object,
                          const uintmax_t at,
                          const struct triggerfish_weak **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_get_error_index_out_of_bounds(void **state) {
    const struct butterflyfish_fixed_list_wr fixed_list_wr = {
            .get = get_emit_error
    };
    struct object {
        const struct butterflyfish_fixed_list_wr *fixed_list_wr;
    };
    struct object instance = {
            .fixed_list_wr = &fixed_list_wr
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_FIXED_LIST_WR_ERROR_INDEX_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_fixed_list_wr_get(
                    (const struct butterflyfish_fixed_list_wr *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_INDEX_IS_OUT_OF_BOUNDS);
}

static void check_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_fixed_list_wr_set(NULL, 0, (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL);
}

static void check_set_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_fixed_list_wr_set((void *) 1, 0, NULL),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_VALUE_IS_NULL);
}

static int set_emit_error(void *const object,
                          const uintmax_t at,
                          const struct triggerfish_weak *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    return mock();
}

static void check_set_error_index_out_of_bounds(void **state) {
    const struct butterflyfish_fixed_list_wr fixed_list_wr = {
            .set = set_emit_error
    };
    struct object {
        const struct butterflyfish_fixed_list_wr *fixed_list_wr;
    };
    struct object instance = {
            .fixed_list_wr = &fixed_list_wr
    };
    expect_function_call(set_emit_error);
    will_return(set_emit_error,
                BUTTERFLYFISH_FIXED_LIST_WR_ERROR_INDEX_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_fixed_list_wr_set(
                    (struct butterflyfish_fixed_list_wr *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_INDEX_IS_OUT_OF_BOUNDS);
}

static void check_set_error_memory_allocation_failed(void **state) {
    const struct butterflyfish_fixed_list_wr fixed_list_wr = {
            .set = set_emit_error
    };
    struct object {
        const struct butterflyfish_fixed_list_wr *fixed_list_wr;
    };
    struct object instance = {
            .fixed_list_wr = &fixed_list_wr
    };
    expect_function_call(set_emit_error);
    will_return(set_emit_error,
                BUTTERFLYFISH_FIXED_LIST_WR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_fixed_list_wr_set(
                    (struct butterflyfish_fixed_list_wr *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_at_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_fixed_list_wr_at(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL);
}

static void check_at_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_fixed_list_wr_at((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_ITEM_IS_NULL);
}

static void check_at_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_fixed_list_wr_at((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OUT_IS_NULL);
}

static int at_emit_error(const void *const object,
                         const struct triggerfish_weak *const item,
                         uintmax_t *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

static void check_at_error_item_is_out_of_bounds(void **state) {
    const struct butterflyfish_fixed_list_wr fixed_list_wr = {
            .at = at_emit_error
    };
    struct object {
        const struct butterflyfish_fixed_list_wr *fixed_list_wr;
    };
    struct object instance = {
            .fixed_list_wr = &fixed_list_wr
    };
    expect_function_call(at_emit_error);
    will_return(at_emit_error,
                BUTTERFLYFISH_FIXED_LIST_WR_ERROR_ITEM_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_fixed_list_wr_at(
                    (struct butterflyfish_fixed_list_wr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_WR_ERROR_ITEM_IS_OUT_OF_BOUNDS);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_fixed_list_is_empty),
            cmocka_unit_test(check_as_collection_first_error_on_collection_is_empty),
            cmocka_unit_test(check_as_stream_first_error_on_stream_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_fixed_list_is_empty),
            cmocka_unit_test(check_as_collection_last_error_on_collection_is_empty),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_item_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_collection_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_stream_next_error_on_end_of_sequence),
            cmocka_unit_test(check_prev_error_on_object_is_null),
            cmocka_unit_test(check_prev_error_on_item_is_null),
            cmocka_unit_test(check_prev_error_on_out_is_null),
            cmocka_unit_test(check_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_as_collection_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_get_error_on_object_is_null),
            cmocka_unit_test(check_get_error_on_out),
            cmocka_unit_test(check_get_error_index_out_of_bounds),
            cmocka_unit_test(check_set_error_on_object_is_null),
            cmocka_unit_test(check_set_error_on_value_is_null),
            cmocka_unit_test(check_set_error_index_out_of_bounds),
            cmocka_unit_test(check_set_error_memory_allocation_failed),
            cmocka_unit_test(check_at_error_on_object_is_null),
            cmocka_unit_test(check_at_error_on_item_is_null),
            cmocka_unit_test(check_at_error_on_out_is_null),
            cmocka_unit_test(check_at_error_item_is_out_of_bounds),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
