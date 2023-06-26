#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_wr_count(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_wr_count((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_OUT_IS_NULL);
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
    const struct butterflyfish_reducible_queue_wr reducible_queue_wr = {
            .collection_wr.count = count
    };
    struct object {
        const struct butterflyfish_reducible_queue_wr *reducible_queue_wr;
    };
    struct object instance = {
            .reducible_queue_wr = &reducible_queue_wr
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_reducible_queue_wr_count(
                    (const struct butterflyfish_reducible_queue_wr *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static void check_as_collection_count(void **state) {
    srand(time(NULL));
    const struct butterflyfish_reducible_queue_wr reducible_queue_wr = {
            .collection_wr.count = count
    };
    struct object {
        const struct butterflyfish_reducible_queue_wr *reducible_queue_wr;
    };
    struct object instance = {
            .reducible_queue_wr = &reducible_queue_wr
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_collection_wr_count(
                    (const struct butterflyfish_collection_wr *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static int fl_emit_error(const void *const object,
                         const struct triggerfish_weak **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_first_error_on_queue_is_empty(void **state) {
    const struct butterflyfish_reducible_queue_wr queue_wr = {
            .collection_wr.stream_wr.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_wr *queue_wr;
    };
    struct object instance = {
            .queue_wr = &queue_wr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_reducible_queue_wr_first(
                    (const struct butterflyfish_reducible_queue_wr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_QUEUE_IS_EMPTY);
}

static void
check_as_collection_first_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_reducible_queue_wr queue_wr = {
            .collection_wr.stream_wr.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_wr *queue_wr;
    };
    struct object instance = {
            .queue_wr = &queue_wr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_wr_first(
                    (const struct butterflyfish_collection_wr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_WR_ERROR_COLLECTION_IS_EMPTY);
}

static void check_as_stream_first_error_on_stream_is_empty(void **state) {
    const struct butterflyfish_reducible_queue_wr queue_wr = {
            .collection_wr.stream_wr.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_wr *queue_wr;
    };
    struct object instance = {
            .queue_wr = &queue_wr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stream_wr_first(
                    (const struct butterflyfish_stream_wr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_WR_ERROR_STREAM_IS_EMPTY);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_wr_first(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_wr_first((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_wr_last(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_wr_last((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_queue_is_empty(void **state) {
    const struct butterflyfish_reducible_queue_wr queue_wr = {
            .collection_wr.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_wr *queue_wr;
    };
    struct object instance = {
            .queue_wr = &queue_wr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_reducible_queue_wr_last(
                    (const struct butterflyfish_reducible_queue_wr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_QUEUE_IS_EMPTY);
}

static void
check_as_collection_last_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_collection_wr collection_wr = {
            .last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_collection_wr *collection_wr;
    };
    struct object instance = {
            .collection_wr = &collection_wr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_wr_last(
                    (const struct butterflyfish_collection_wr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_WR_ERROR_COLLECTION_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_wr_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_wr_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_wr_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_OUT_IS_NULL);
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
    const struct butterflyfish_reducible_queue_wr queue_wr = {
            .collection_wr.stream_wr.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_wr *queue_wr;
    };
    struct object instance = {
            .queue_wr = &queue_wr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_reducible_queue_wr_next(
                    (const struct butterflyfish_reducible_queue_wr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_queue_wr queue_wr = {
            .collection_wr.stream_wr.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_wr *queue_wr;
    };
    struct object instance = {
            .queue_wr = &queue_wr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_wr_next(
                    (const struct butterflyfish_collection_wr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_WR_ERROR_END_OF_SEQUENCE);
}

static void check_as_stream_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_queue_wr queue_wr = {
            .collection_wr.stream_wr.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_wr *queue_wr;
    };
    struct object instance = {
            .queue_wr = &queue_wr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stream_wr_next(
                    (const struct butterflyfish_stream_wr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_WR_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_wr_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_wr_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_wr_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_queue_wr queue_wr = {
            .collection_wr.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_wr *queue_wr;
    };
    struct object instance = {
            .queue_wr = &queue_wr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_reducible_queue_wr_prev(
                    (const struct butterflyfish_reducible_queue_wr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_queue_wr queue_wr = {
            .collection_wr.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_wr *queue_wr;
    };
    struct object instance = {
            .queue_wr = &queue_wr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_wr_prev(
                    (const struct butterflyfish_collection_wr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_WR_ERROR_END_OF_SEQUENCE);
}

static void check_remove_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_wr_remove(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_OBJECT_IS_NULL);
}

static void check_remove_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_wr_remove((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_OUT_IS_NULL);
}

static int
remove_emit_error(void *const object,
                  struct triggerfish_weak **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_remove_error_on_queue_is_empty(void **state) {
    const struct butterflyfish_reducible_queue_wr queue_wr = {
            .remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_wr *queue_wr;
    };
    struct object instance = {
            .queue_wr = &queue_wr
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_reducible_queue_wr_remove(
                    (struct butterflyfish_reducible_queue_wr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_QUEUE_IS_EMPTY);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_count),
            cmocka_unit_test(check_as_collection_count),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_queue_is_empty),
            cmocka_unit_test(check_as_collection_first_error_on_collection_is_empty),
            cmocka_unit_test(check_as_stream_first_error_on_stream_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_queue_is_empty),
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
            cmocka_unit_test(check_remove_error_on_object_is_null),
            cmocka_unit_test(check_remove_error_on_out_is_null),
            cmocka_unit_test(check_remove_error_on_queue_is_empty),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
