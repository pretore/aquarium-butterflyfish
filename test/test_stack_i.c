#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_i_count(NULL, (void *) 1),
            BUTTERFLYFISH_STACK_I_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_i_count((void *) 1, NULL),
            BUTTERFLYFISH_STACK_I_ERROR_OUT_IS_NULL);
}

static int fl_emit_error(const void *const object,
                         const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_first_error_on_stack_is_empty(void **state) {
    const struct butterflyfish_stack_i stack_i = {
            .collection_i.stream_i.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_stack_i *stack_i;
    };
    struct object instance = {
            .stack_i = &stack_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_STACK_I_ERROR_STACK_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stack_i_first(
                    (const struct butterflyfish_stack_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STACK_I_ERROR_STACK_IS_EMPTY);
}

static void check_as_collection_first_error_on_stack_is_empty(void **state) {
    const struct butterflyfish_stack_i stack_i = {
            .collection_i.stream_i.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_stack_i *stack_i;
    };
    struct object instance = {
            .stack_i = &stack_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_STACK_I_ERROR_STACK_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_i_first(
                    (const struct butterflyfish_collection_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_ERROR_COLLECTION_IS_EMPTY);
}

static void check_as_stream_first_error_on_stream_is_empty(void **state) {
    const struct butterflyfish_stack_i stack_i = {
            .collection_i.stream_i.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_stack_i *stack_i;
    };
    struct object instance = {
            .stack_i = &stack_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_STACK_I_ERROR_STACK_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stream_i_first(
                    (const struct butterflyfish_stream_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_I_ERROR_STREAM_IS_EMPTY);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_i_first(NULL, (void *) 1),
            BUTTERFLYFISH_STACK_I_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_i_first((void *) 1, NULL),
            BUTTERFLYFISH_STACK_I_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_i_last(NULL, (void *) 1),
            BUTTERFLYFISH_STACK_I_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_i_last((void *) 1, NULL),
            BUTTERFLYFISH_STACK_I_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_stack_is_empty(void **state) {
    const struct butterflyfish_stack_i stack_i = {
            .collection_i.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_stack_i *stack_i;
    };
    struct object instance = {
            .stack_i = &stack_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_STACK_I_ERROR_STACK_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stack_i_last(
                    (const struct butterflyfish_stack_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STACK_I_ERROR_STACK_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_i_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_STACK_I_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_i_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_STACK_I_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_i_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_STACK_I_ERROR_OUT_IS_NULL);
}

static int np_emit_error(const void *const object,
                         const struct sea_turtle_integer *const item,
                         const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_stack_i stack_i = {
            .collection_i.stream_i.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_stack_i *stack_i;
    };
    struct object instance = {
            .stack_i = &stack_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_STACK_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stack_i_next(
                    (const struct butterflyfish_stack_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STACK_I_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_stack_i stack_i = {
            .collection_i.stream_i.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_stack_i *stack_i;
    };
    struct object instance = {
            .stack_i = &stack_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_STACK_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_i_next(
                    (const struct butterflyfish_collection_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STACK_I_ERROR_END_OF_SEQUENCE);
}

static void check_as_stream_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_stack_i stack_i = {
            .collection_i.stream_i.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_stack_i *stack_i;
    };
    struct object instance = {
            .stack_i = &stack_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_STACK_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stream_i_next(
                    (const struct butterflyfish_stream_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_I_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_i_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_STACK_I_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_i_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_STACK_I_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_i_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_STACK_I_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_stack_i stack_i = {
            .collection_i.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_stack_i *stack_i;
    };
    struct object instance = {
            .stack_i = &stack_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_STACK_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stack_i_prev(
                    (const struct butterflyfish_stack_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STACK_I_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_stack_i stack_i = {
            .collection_i.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_stack_i *stack_i;
    };
    struct object instance = {
            .stack_i = &stack_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_STACK_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_i_prev(
                    (const struct butterflyfish_collection_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_ERROR_END_OF_SEQUENCE);
}

static void check_push_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_i_push(NULL, (void *) 1),
            BUTTERFLYFISH_STACK_I_ERROR_OBJECT_IS_NULL);
}

static void check_push_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_i_push((void *) 1, NULL),
            BUTTERFLYFISH_STACK_I_ERROR_VALUE_IS_NULL);
}

static int push_emit_error(void *const object,
                           const struct sea_turtle_integer *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    return mock();
}

static void check_push_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_stack_i stack_i = {
            .push = push_emit_error
    };
    struct object {
        const struct butterflyfish_stack_i *stack_i;
    };
    struct object instance = {
            .stack_i = &stack_i
    };
    expect_function_call(push_emit_error);
    will_return(push_emit_error,
                BUTTERFLYFISH_STACK_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_stack_i_push(
                    (struct butterflyfish_stack_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STACK_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_pop_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_i_pop(NULL, (void *) 1),
            BUTTERFLYFISH_STACK_I_ERROR_OBJECT_IS_NULL);
}

static void check_pop_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_i_pop((void *) 1, NULL),
            BUTTERFLYFISH_STACK_I_ERROR_OUT_IS_NULL);
}

static int pop_emit_error(void *const object,
                          struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_pop_error_on_stack_is_empty(void **state) {
    const struct butterflyfish_stack_i stack_i = {
            .pop = pop_emit_error
    };
    struct object {
        const struct butterflyfish_stack_i *stack_i;
    };
    struct object instance = {
            .stack_i = &stack_i
    };
    expect_function_call(pop_emit_error);
    will_return(pop_emit_error,
                BUTTERFLYFISH_STACK_I_ERROR_STACK_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stack_i_pop(
                    (struct butterflyfish_stack_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STACK_I_ERROR_STACK_IS_EMPTY);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_stack_is_empty),
            cmocka_unit_test(check_as_collection_first_error_on_stack_is_empty),
            cmocka_unit_test(check_as_stream_first_error_on_stream_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_stack_is_empty),
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
            cmocka_unit_test(check_push_error_on_object_is_null),
            cmocka_unit_test(check_push_error_on_value_is_null),
            cmocka_unit_test(check_push_error_on_memory_allocation_failed),
            cmocka_unit_test(check_pop_error_on_object_is_null),
            cmocka_unit_test(check_pop_error_on_out_is_null),
            cmocka_unit_test(check_pop_error_on_stack_is_empty),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
