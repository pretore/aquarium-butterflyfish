#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

static void check_as_stream_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_s_as_stream(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OBJECT_IS_NULL);
}

static void check_as_stream_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_s_as_stream((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OUT_IS_NULL);
}

static void check_as_stream(void **state) {
    struct butterflyfish_reducible_queue_s reducible_queue = {};
    const struct butterflyfish_stream_s *stream;
    assert_int_equal(butterflyfish_reducible_queue_s_as_stream(
            &reducible_queue, &stream), 0);
    assert_ptr_equal(&reducible_queue, stream);
}

static void check_as_collection_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_s_as_collection(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OBJECT_IS_NULL);
}

static void check_as_collection_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_s_as_collection((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OUT_IS_NULL);
}

static void check_as_collection(void **state) {
    struct butterflyfish_reducible_queue_s reducible_queue = {};
    const struct butterflyfish_collection_s *collection;
    assert_int_equal(butterflyfish_reducible_queue_s_as_collection(
            &reducible_queue, &collection), 0);
    assert_ptr_equal(&reducible_queue, collection);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_s_count(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_s_count((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OUT_IS_NULL);
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
    const struct butterflyfish_reducible_queue_s reducible_queue_s = {
            .collection_s.count = count
    };
    struct object {
        const struct butterflyfish_reducible_queue_s *reducible_queue_s;
    };
    struct object instance = {
            .reducible_queue_s = &reducible_queue_s
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_reducible_queue_s_count(
                    (const struct butterflyfish_reducible_queue_s *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static void check_as_collection_count(void **state) {
    srand(time(NULL));
    const struct butterflyfish_reducible_queue_s reducible_queue_s = {
            .collection_s.count = count
    };
    struct object {
        const struct butterflyfish_reducible_queue_s *reducible_queue_s;
    };
    struct object instance = {
            .reducible_queue_s = &reducible_queue_s
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_collection_s_count(
                    (const struct butterflyfish_collection_s *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static int fl_emit_error(const void *const object,
                         const struct sea_turtle_string **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_first_error_on_queue_is_empty(void **state) {
    const struct butterflyfish_reducible_queue_s queue_s = {
            .collection_s.stream_s.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_s *queue_s;
    };
    struct object instance = {
            .queue_s = &queue_s
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_reducible_queue_s_first(
                    (const struct butterflyfish_reducible_queue_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_QUEUE_IS_EMPTY);
}

static void
check_as_collection_first_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_reducible_queue_s queue_s = {
            .collection_s.stream_s.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_s *queue_s;
    };
    struct object instance = {
            .queue_s = &queue_s
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_s_first(
                    (const struct butterflyfish_collection_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_S_ERROR_COLLECTION_IS_EMPTY);
}

static void check_as_stream_first_error_on_stream_is_empty(void **state) {
    const struct butterflyfish_reducible_queue_s queue_s = {
            .collection_s.stream_s.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_s *queue_s;
    };
    struct object instance = {
            .queue_s = &queue_s
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stream_s_first(
                    (const struct butterflyfish_stream_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_S_ERROR_STREAM_IS_EMPTY);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_s_first(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_s_first((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_s_last(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_s_last((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_queue_is_empty(void **state) {
    const struct butterflyfish_reducible_queue_s queue_s = {
            .collection_s.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_s *queue_s;
    };
    struct object instance = {
            .queue_s = &queue_s
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_reducible_queue_s_last(
                    (const struct butterflyfish_reducible_queue_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_QUEUE_IS_EMPTY);
}

static void
check_as_collection_last_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_collection_s collection_s = {
            .last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_collection_s *collection_s;
    };
    struct object instance = {
            .collection_s = &collection_s
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_s_last(
                    (const struct butterflyfish_collection_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_S_ERROR_COLLECTION_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_s_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_s_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_s_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OUT_IS_NULL);
}

static int np_emit_error(const void *const object,
                         const struct sea_turtle_string *const item,
                         const struct sea_turtle_string **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_queue_s queue_s = {
            .collection_s.stream_s.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_s *queue_s;
    };
    struct object instance = {
            .queue_s = &queue_s
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_reducible_queue_s_next(
                    (const struct butterflyfish_reducible_queue_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_queue_s queue_s = {
            .collection_s.stream_s.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_s *queue_s;
    };
    struct object instance = {
            .queue_s = &queue_s
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_s_next(
                    (const struct butterflyfish_collection_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_S_ERROR_END_OF_SEQUENCE);
}

static void check_as_stream_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_queue_s queue_s = {
            .collection_s.stream_s.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_s *queue_s;
    };
    struct object instance = {
            .queue_s = &queue_s
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stream_s_next(
                    (const struct butterflyfish_stream_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_S_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_s_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_s_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_s_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_queue_s queue_s = {
            .collection_s.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_s *queue_s;
    };
    struct object instance = {
            .queue_s = &queue_s
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_reducible_queue_s_prev(
                    (const struct butterflyfish_reducible_queue_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_queue_s queue_s = {
            .collection_s.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_s *queue_s;
    };
    struct object instance = {
            .queue_s = &queue_s
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_s_prev(
                    (const struct butterflyfish_collection_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_S_ERROR_END_OF_SEQUENCE);
}

static void check_remove_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_s_remove(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OBJECT_IS_NULL);
}

static void check_remove_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_queue_s_remove((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OUT_IS_NULL);
}

static int
remove_emit_error(void *const object,
                  struct sea_turtle_string *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_remove_error_on_queue_is_empty(void **state) {
    const struct butterflyfish_reducible_queue_s queue_s = {
            .remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_queue_s *queue_s;
    };
    struct object instance = {
            .queue_s = &queue_s
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_reducible_queue_s_remove(
                    (struct butterflyfish_reducible_queue_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_QUEUE_IS_EMPTY);
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
