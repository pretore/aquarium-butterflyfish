#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_s_count(NULL, (void *) 1),
            BUTTERFLYFISH_STACK_S_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_s_count((void *) 1, NULL),
            BUTTERFLYFISH_STACK_S_ERROR_OUT_IS_NULL);
}

static int fl_emit_error(const void *const object,
                         const struct sea_turtle_string **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_first_error_on_stack_is_empty(void **state) {
    const struct butterflyfish_stack_s stack_s = {
            .reducible_stack_s.collection_s.stream_s.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_stack_s *stack_s;
    };
    struct object instance = {
            .stack_s = &stack_s
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_STACK_S_ERROR_STACK_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stack_s_first(
                    (const struct butterflyfish_stack_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STACK_S_ERROR_STACK_IS_EMPTY);
}

static void
check_as_reducible_stack_first_error_on_stack_is_empty(void **state) {
    const struct butterflyfish_stack_s stack_s = {
            .reducible_stack_s.collection_s.stream_s.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_stack_s *stack_s;
    };
    struct object instance = {
            .stack_s = &stack_s
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_STACK_S_ERROR_STACK_IS_EMPTY);
    assert_int_equal(
            butterflyfish_reducible_stack_s_first(
                    (const struct butterflyfish_reducible_stack_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_STACK_S_ERROR_STACK_IS_EMPTY);
}

static void
check_as_collection_first_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_stack_s stack_s = {
            .reducible_stack_s.collection_s.stream_s.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_stack_s *stack_s;
    };
    struct object instance = {
            .stack_s = &stack_s
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_STACK_S_ERROR_STACK_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_s_first(
                    (const struct butterflyfish_collection_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_S_ERROR_COLLECTION_IS_EMPTY);
}

static void check_as_stream_first_error_on_stream_is_empty(void **state) {
    const struct butterflyfish_stack_s stack_s = {
            .reducible_stack_s.collection_s.stream_s.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_stack_s *stack_s;
    };
    struct object instance = {
            .stack_s = &stack_s
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_STACK_S_ERROR_STACK_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stream_s_first(
                    (const struct butterflyfish_stream_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_S_ERROR_STREAM_IS_EMPTY);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_s_first(NULL, (void *) 1),
            BUTTERFLYFISH_STACK_S_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_s_first((void *) 1, NULL),
            BUTTERFLYFISH_STACK_S_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_s_last(NULL, (void *) 1),
            BUTTERFLYFISH_STACK_S_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_s_last((void *) 1, NULL),
            BUTTERFLYFISH_STACK_S_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_stack_is_empty(void **state) {
    const struct butterflyfish_stack_s stack_s = {
            .reducible_stack_s.collection_s.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_stack_s *stack_s;
    };
    struct object instance = {
            .stack_s = &stack_s
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_STACK_S_ERROR_STACK_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stack_s_last(
                    (const struct butterflyfish_stack_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STACK_S_ERROR_STACK_IS_EMPTY);
}

static void
check_as_reducible_stack_last_error_on_stack_is_empty(void **state) {
    const struct butterflyfish_stack_s stack_s = {
            .reducible_stack_s.collection_s.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_stack_s *stack_s;
    };
    struct object instance = {
            .stack_s = &stack_s
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_STACK_S_ERROR_STACK_IS_EMPTY);
    assert_int_equal(
            butterflyfish_reducible_stack_s_last(
                    (const struct butterflyfish_reducible_stack_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_STACK_S_ERROR_STACK_IS_EMPTY);
}

static void
check_as_collection_last_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_stack_s stack_s = {
            .reducible_stack_s.collection_s.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_stack_s *stack_s;
    };
    struct object instance = {
            .stack_s = &stack_s
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_STACK_S_ERROR_STACK_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_s_last(
                    (const struct butterflyfish_collection_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_S_ERROR_COLLECTION_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_s_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_STACK_S_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_s_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_STACK_S_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_s_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_STACK_S_ERROR_OUT_IS_NULL);
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
    const struct butterflyfish_stack_s stack_s = {
            .reducible_stack_s.collection_s.stream_s.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_stack_s *stack_s;
    };
    struct object instance = {
            .stack_s = &stack_s
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_STACK_S_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stack_s_next(
                    (const struct butterflyfish_stack_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STACK_S_ERROR_END_OF_SEQUENCE);
}

static void
check_as_reducible_stack_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_stack_s stack_s = {
            .reducible_stack_s.collection_s.stream_s.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_stack_s *stack_s;
    };
    struct object instance = {
            .stack_s = &stack_s
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_STACK_S_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_reducible_stack_s_next(
                    (const struct butterflyfish_reducible_stack_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_STACK_S_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_stack_s stack_s = {
            .reducible_stack_s.collection_s.stream_s.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_stack_s *stack_s;
    };
    struct object instance = {
            .stack_s = &stack_s
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_STACK_S_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_s_next(
                    (const struct butterflyfish_collection_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STACK_S_ERROR_END_OF_SEQUENCE);
}

static void check_as_stream_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_stack_s stack_s = {
            .reducible_stack_s.collection_s.stream_s.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_stack_s *stack_s;
    };
    struct object instance = {
            .stack_s = &stack_s
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_STACK_S_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stream_s_next(
                    (const struct butterflyfish_stream_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_S_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_s_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_STACK_S_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_s_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_STACK_S_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_s_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_STACK_S_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_stack_s stack_s = {
            .reducible_stack_s.collection_s.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_stack_s *stack_s;
    };
    struct object instance = {
            .stack_s = &stack_s
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_STACK_S_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stack_s_prev(
                    (const struct butterflyfish_stack_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STACK_S_ERROR_END_OF_SEQUENCE);
}

static void
check_as_reducible_stack_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_stack_s stack_s = {
            .reducible_stack_s.collection_s.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_stack_s *stack_s;
    };
    struct object instance = {
            .stack_s = &stack_s
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_STACK_S_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_reducible_stack_s_prev(
                    (const struct butterflyfish_reducible_stack_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_STACK_S_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_stack_s stack_s = {
            .reducible_stack_s.collection_s.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_stack_s *stack_s;
    };
    struct object instance = {
            .stack_s = &stack_s
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_STACK_S_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_s_prev(
                    (const struct butterflyfish_collection_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_S_ERROR_END_OF_SEQUENCE);
}

static void check_pop_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_s_pop(NULL, (void *) 1),
            BUTTERFLYFISH_STACK_S_ERROR_OBJECT_IS_NULL);
}

static void check_pop_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_s_pop((void *) 1, NULL),
            BUTTERFLYFISH_STACK_S_ERROR_OUT_IS_NULL);
}

static int pop_emit_error(void *const object,
                          struct sea_turtle_string **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_pop_error_on_stack_is_empty(void **state) {
    const struct butterflyfish_stack_s stack_s = {
            .reducible_stack_s.pop = pop_emit_error
    };
    struct object {
        const struct butterflyfish_stack_s *stack_s;
    };
    struct object instance = {
            .stack_s = &stack_s
    };
    expect_function_call(pop_emit_error);
    will_return(pop_emit_error,
                BUTTERFLYFISH_STACK_S_ERROR_STACK_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stack_s_pop(
                    (struct butterflyfish_stack_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STACK_S_ERROR_STACK_IS_EMPTY);
}

static void check_push_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_s_push(NULL, (void *) 1),
            BUTTERFLYFISH_STACK_S_ERROR_OBJECT_IS_NULL);
}

static void check_push_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_s_push((void *) 1, NULL),
            BUTTERFLYFISH_STACK_S_ERROR_VALUE_IS_NULL);
}

static int push_emit_error(void *const object,
                           const struct sea_turtle_string *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    return mock();
}

static void check_push_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_stack_s stack_s = {
            .push = push_emit_error
    };
    struct object {
        const struct butterflyfish_stack_s *stack_s;
    };
    struct object instance = {
            .stack_s = &stack_s
    };
    expect_function_call(push_emit_error);
    will_return(push_emit_error,
                BUTTERFLYFISH_STACK_S_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_stack_s_push(
                    (struct butterflyfish_stack_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STACK_S_ERROR_MEMORY_ALLOCATION_FAILED);
}

static int
push_all_emit_error(void *const object,
                    const struct butterflyfish_stream_s *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static void check_push_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_s_push_all(NULL, (void *) 1),
            BUTTERFLYFISH_STACK_S_ERROR_OBJECT_IS_NULL);
}

static void check_push_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_s_push_all((void *) 1, NULL),
            BUTTERFLYFISH_STACK_S_ERROR_OTHER_IS_NULL);
}

static void check_push_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_stack_s stack_s = {
            .push_all = push_all_emit_error
    };
    struct object {
        const struct butterflyfish_stack_s *stack_s;
    };
    struct object instance = {
            .stack_s = &stack_s
    };
    expect_function_call(push_all_emit_error);
    will_return(push_all_emit_error,
                BUTTERFLYFISH_STACK_S_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_stack_s_push_all(
                    (struct butterflyfish_stack_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STACK_S_ERROR_MEMORY_ALLOCATION_FAILED);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_stack_is_empty),
            cmocka_unit_test(check_as_reducible_stack_first_error_on_stack_is_empty),
            cmocka_unit_test(check_as_collection_first_error_on_collection_is_empty),
            cmocka_unit_test(check_as_stream_first_error_on_stream_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_stack_is_empty),
            cmocka_unit_test(check_as_reducible_stack_last_error_on_stack_is_empty),
            cmocka_unit_test(check_as_collection_last_error_on_collection_is_empty),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_item_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_reducible_stack_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_collection_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_stream_next_error_on_end_of_sequence),
            cmocka_unit_test(check_prev_error_on_object_is_null),
            cmocka_unit_test(check_prev_error_on_item_is_null),
            cmocka_unit_test(check_prev_error_on_out_is_null),
            cmocka_unit_test(check_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_as_reducible_stack_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_as_collection_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_pop_error_on_object_is_null),
            cmocka_unit_test(check_pop_error_on_out_is_null),
            cmocka_unit_test(check_pop_error_on_stack_is_empty),
            cmocka_unit_test(check_push_error_on_object_is_null),
            cmocka_unit_test(check_push_error_on_value_is_null),
            cmocka_unit_test(check_push_error_on_memory_allocation_failed),
            cmocka_unit_test(check_push_all_error_on_object_is_null),
            cmocka_unit_test(check_push_all_error_on_other_is_null),
            cmocka_unit_test(check_push_all_error_on_memory_allocation_failed),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
