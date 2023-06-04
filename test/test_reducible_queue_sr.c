#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_sr_count(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_sr_count((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OUT_IS_NULL);
}

static int fl_emit_error(const void *const object,
                         struct triggerfish_strong **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_first_error_on_queue_is_empty(void **state) {
    const struct butterflyfish_reducible_queue_sr queue_sr = {
            .collection_sr.stream_sr.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_sr *queue_sr;
    };
    struct object instance = {
            .queue_sr = &queue_sr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_reducible_queue_sr_first(
                    (const struct butterflyfish_reducible_queue_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_QUEUE_IS_EMPTY);
}

static void
check_as_collection_first_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_reducible_queue_sr queue_sr = {
            .collection_sr.stream_sr.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_sr *queue_sr;
    };
    struct object instance = {
            .queue_sr = &queue_sr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_sr_first(
                    (const struct butterflyfish_collection_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_SR_ERROR_COLLECTION_IS_EMPTY);
}

static void check_as_stream_first_error_on_stream_is_empty(void **state) {
    const struct butterflyfish_reducible_queue_sr queue_sr = {
            .collection_sr.stream_sr.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_sr *queue_sr;
    };
    struct object instance = {
            .queue_sr = &queue_sr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stream_sr_first(
                    (const struct butterflyfish_stream_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_SR_ERROR_STREAM_IS_EMPTY);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_sr_first(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_sr_first((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_sr_last(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_sr_last((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_queue_is_empty(void **state) {
    const struct butterflyfish_reducible_queue_sr queue_sr = {
            .collection_sr.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_sr *queue_sr;
    };
    struct object instance = {
            .queue_sr = &queue_sr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_reducible_queue_sr_last(
                    (const struct butterflyfish_reducible_queue_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_QUEUE_IS_EMPTY);
}

static void
check_as_collection_last_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_collection_sr collection_sr = {
            .last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_collection_sr *collection_sr;
    };
    struct object instance = {
            .collection_sr = &collection_sr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_sr_last(
                    (const struct butterflyfish_collection_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_SR_ERROR_COLLECTION_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_sr_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_sr_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_sr_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OUT_IS_NULL);
}

static int np_emit_error(const void *const object,
                         const struct triggerfish_strong *const item,
                         struct triggerfish_strong **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_queue_sr queue_sr = {
            .collection_sr.stream_sr.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_sr *queue_sr;
    };
    struct object instance = {
            .queue_sr = &queue_sr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_reducible_queue_sr_next(
                    (const struct butterflyfish_reducible_queue_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_queue_sr queue_sr = {
            .collection_sr.stream_sr.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_sr *queue_sr;
    };
    struct object instance = {
            .queue_sr = &queue_sr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_sr_next(
                    (const struct butterflyfish_collection_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_SR_ERROR_END_OF_SEQUENCE);
}

static void check_as_stream_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_queue_sr queue_sr = {
            .collection_sr.stream_sr.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_sr *queue_sr;
    };
    struct object instance = {
            .queue_sr = &queue_sr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stream_sr_next(
                    (const struct butterflyfish_stream_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_SR_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_sr_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_sr_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_sr_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_queue_sr queue_sr = {
            .collection_sr.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_sr *queue_sr;
    };
    struct object instance = {
            .queue_sr = &queue_sr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_reducible_queue_sr_prev(
                    (const struct butterflyfish_reducible_queue_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_queue_sr queue_sr = {
            .collection_sr.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_sr *queue_sr;
    };
    struct object instance = {
            .queue_sr = &queue_sr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_sr_prev(
                    (const struct butterflyfish_collection_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_SR_ERROR_END_OF_SEQUENCE);
}

static void check_remove_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_sr_remove(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OBJECT_IS_NULL);
}

static void check_remove_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_sr_remove((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_OUT_IS_NULL);
}

static int
remove_emit_error(void *const object,
                  struct triggerfish_strong **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_remove_error_on_queue_is_empty(void **state) {
    const struct butterflyfish_reducible_queue_sr queue_sr = {
            .remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_sr *queue_sr;
    };
    struct object instance = {
            .queue_sr = &queue_sr
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_reducible_queue_sr_remove(
                    (struct butterflyfish_reducible_queue_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_SR_ERROR_QUEUE_IS_EMPTY);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
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
