#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

static void check_as_stream_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_sr_as_stream(NULL, (void *) 1),
            BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL);
}

static void check_as_stream_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_sr_as_stream((void *) 1, NULL),
            BUTTERFLYFISH_STACK_SR_ERROR_OUT_IS_NULL);
}

static void check_as_stream(void **state) {
    struct butterflyfish_stack_sr stack = {};
    const struct butterflyfish_stream_sr *stream;
    assert_int_equal(butterflyfish_stack_sr_as_stream(&stack, &stream), 0);
    assert_ptr_equal(&stack, stream);
}

static void check_as_collection_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_sr_as_collection(NULL, (void *) 1),
            BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL);
}

static void check_as_collection_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_sr_as_collection((void *) 1, NULL),
            BUTTERFLYFISH_STACK_SR_ERROR_OUT_IS_NULL);
}

static void check_as_collection(void **state) {
    struct butterflyfish_stack_sr stack = {};
    const struct butterflyfish_collection_sr *collection;
    assert_int_equal(butterflyfish_stack_sr_as_collection(
            &stack, &collection), 0);
    assert_ptr_equal(&stack, collection);
}

static void check_as_reducible_stack_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_sr_as_reducible_stack(NULL, (void *) 1),
            BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL);
}

static void check_as_reducible_stack_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_sr_as_reducible_stack((void *) 1, NULL),
            BUTTERFLYFISH_STACK_SR_ERROR_OUT_IS_NULL);
}

static void check_as_reducible_stack(void **state) {
    struct butterflyfish_stack_sr stack = {};
    struct butterflyfish_reducible_stack_sr *reducible_stack;
    assert_int_equal(butterflyfish_stack_sr_as_reducible_stack(
            &stack, &reducible_stack), 0);
    assert_ptr_equal(&stack, reducible_stack);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_sr_count(NULL, (void *) 1),
            BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_sr_count((void *) 1, NULL),
            BUTTERFLYFISH_STACK_SR_ERROR_OUT_IS_NULL);
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
    const struct butterflyfish_stack_sr stack_sr = {
            .reducible_stack_sr.collection_sr.count = count
    };
    struct object {
        const struct butterflyfish_stack_sr *stack_sr;
    };
    struct object instance = {
            .stack_sr = &stack_sr
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_stack_sr_count(
                    (const struct butterflyfish_stack_sr *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static void check_as_reducible_stack_count(void **state) {
    srand(time(NULL));
    const struct butterflyfish_stack_sr stack_sr = {
            .reducible_stack_sr.collection_sr.count = count
    };
    struct object {
        const struct butterflyfish_stack_sr *stack_sr;
    };
    struct object instance = {
            .stack_sr = &stack_sr
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_stack_sr_count(
                    (const struct butterflyfish_stack_sr *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static void check_as_collection_count(void **state) {
    srand(time(NULL));
    const struct butterflyfish_stack_sr stack_sr = {
            .reducible_stack_sr.collection_sr.count = count
    };
    struct object {
        const struct butterflyfish_stack_sr *stack_sr;
    };
    struct object instance = {
            .stack_sr = &stack_sr
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_collection_sr_count(
                    (const struct butterflyfish_collection_sr *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static int fl_emit_error(const void *const object,
                         struct triggerfish_strong **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_first_error_on_stack_is_empty(void **state) {
    const struct butterflyfish_stack_sr stack_sr = {
            .reducible_stack_sr.collection_sr.stream_sr.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_stack_sr *stack_sr;
    };
    struct object instance = {
            .stack_sr = &stack_sr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_STACK_SR_ERROR_STACK_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stack_sr_first(
                    (const struct butterflyfish_stack_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STACK_SR_ERROR_STACK_IS_EMPTY);
}

static void
check_as_reducible_stack_first_error_on_stack_is_empty(void **state) {
    const struct butterflyfish_stack_sr stack_sr = {
            .reducible_stack_sr.collection_sr.stream_sr.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_stack_sr *stack_sr;
    };
    struct object instance = {
            .stack_sr = &stack_sr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_STACK_SR_ERROR_STACK_IS_EMPTY);
    assert_int_equal(
            butterflyfish_reducible_stack_sr_first(
                    (const struct butterflyfish_reducible_stack_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_STACK_SR_ERROR_STACK_IS_EMPTY);
}

static void
check_as_collection_first_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_stack_sr stack_sr = {
            .reducible_stack_sr.collection_sr.stream_sr.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_stack_sr *stack_sr;
    };
    struct object instance = {
            .stack_sr = &stack_sr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_STACK_SR_ERROR_STACK_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_sr_first(
                    (const struct butterflyfish_collection_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_SR_ERROR_COLLECTION_IS_EMPTY);
}

static void check_as_stream_first_error_on_stream_is_empty(void **state) {
    const struct butterflyfish_stack_sr stack_sr = {
            .reducible_stack_sr.collection_sr.stream_sr.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_stack_sr *stack_sr;
    };
    struct object instance = {
            .stack_sr = &stack_sr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_STACK_SR_ERROR_STACK_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stream_sr_first(
                    (const struct butterflyfish_stream_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_SR_ERROR_STREAM_IS_EMPTY);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_sr_first(NULL, (void *) 1),
            BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_sr_first((void *) 1, NULL),
            BUTTERFLYFISH_STACK_SR_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_sr_last(NULL, (void *) 1),
            BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_sr_last((void *) 1, NULL),
            BUTTERFLYFISH_STACK_SR_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_stack_is_empty(void **state) {
    const struct butterflyfish_stack_sr stack_sr = {
            .reducible_stack_sr.collection_sr.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_stack_sr *stack_sr;
    };
    struct object instance = {
            .stack_sr = &stack_sr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_STACK_SR_ERROR_STACK_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stack_sr_last(
                    (const struct butterflyfish_stack_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STACK_SR_ERROR_STACK_IS_EMPTY);
}

static void
check_as_reducible_stack_last_error_on_stack_is_empty(void **state) {
    const struct butterflyfish_stack_sr stack_sr = {
            .reducible_stack_sr.collection_sr.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_stack_sr *stack_sr;
    };
    struct object instance = {
            .stack_sr = &stack_sr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_STACK_SR_ERROR_STACK_IS_EMPTY);
    assert_int_equal(
            butterflyfish_reducible_stack_sr_last(
                    (const struct butterflyfish_reducible_stack_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_STACK_SR_ERROR_STACK_IS_EMPTY);
}

static void
check_as_collection_last_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_stack_sr stack_sr = {
            .reducible_stack_sr.collection_sr.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_stack_sr *stack_sr;
    };
    struct object instance = {
            .stack_sr = &stack_sr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_STACK_SR_ERROR_STACK_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_sr_last(
                    (const struct butterflyfish_collection_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_SR_ERROR_COLLECTION_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_sr_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_sr_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_STACK_SR_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_sr_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_STACK_SR_ERROR_OUT_IS_NULL);
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
    const struct butterflyfish_stack_sr stack_sr = {
            .reducible_stack_sr.collection_sr.stream_sr.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_stack_sr *stack_sr;
    };
    struct object instance = {
            .stack_sr = &stack_sr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_STACK_SR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stack_sr_next(
                    (const struct butterflyfish_stack_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STACK_SR_ERROR_END_OF_SEQUENCE);
}

static void
check_as_reducible_stack_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_stack_sr stack_sr = {
            .reducible_stack_sr.collection_sr.stream_sr.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_stack_sr *stack_sr;
    };
    struct object instance = {
            .stack_sr = &stack_sr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_STACK_SR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_reducible_stack_sr_next(
                    (const struct butterflyfish_reducible_stack_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_STACK_SR_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_stack_sr stack_sr = {
            .reducible_stack_sr.collection_sr.stream_sr.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_stack_sr *stack_sr;
    };
    struct object instance = {
            .stack_sr = &stack_sr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_STACK_SR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_sr_next(
                    (const struct butterflyfish_collection_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STACK_SR_ERROR_END_OF_SEQUENCE);
}

static void check_as_stream_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_stack_sr stack_sr = {
            .reducible_stack_sr.collection_sr.stream_sr.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_stack_sr *stack_sr;
    };
    struct object instance = {
            .stack_sr = &stack_sr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_STACK_SR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stream_sr_next(
                    (const struct butterflyfish_stream_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_SR_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_sr_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_sr_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_STACK_SR_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_sr_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_STACK_SR_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_stack_sr stack_sr = {
            .reducible_stack_sr.collection_sr.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_stack_sr *stack_sr;
    };
    struct object instance = {
            .stack_sr = &stack_sr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_STACK_SR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stack_sr_prev(
                    (const struct butterflyfish_stack_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STACK_SR_ERROR_END_OF_SEQUENCE);
}

static void
check_as_reducible_stack_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_stack_sr stack_sr = {
            .reducible_stack_sr.collection_sr.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_stack_sr *stack_sr;
    };
    struct object instance = {
            .stack_sr = &stack_sr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_STACK_SR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_reducible_stack_sr_prev(
                    (const struct butterflyfish_reducible_stack_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_STACK_SR_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_stack_sr stack_sr = {
            .reducible_stack_sr.collection_sr.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_stack_sr *stack_sr;
    };
    struct object instance = {
            .stack_sr = &stack_sr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_STACK_SR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_sr_prev(
                    (const struct butterflyfish_collection_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_SR_ERROR_END_OF_SEQUENCE);
}

static void check_pop_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_sr_pop(NULL, (void *) 1),
            BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL);
}

static void check_pop_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_sr_pop((void *) 1, NULL),
            BUTTERFLYFISH_STACK_SR_ERROR_OUT_IS_NULL);
}

static int pop_emit_error(void *const object,
                          struct triggerfish_strong **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_pop_error_on_stack_is_empty(void **state) {
    const struct butterflyfish_stack_sr stack_sr = {
            .reducible_stack_sr.pop = pop_emit_error
    };
    struct object {
        const struct butterflyfish_stack_sr *stack_sr;
    };
    struct object instance = {
            .stack_sr = &stack_sr
    };
    expect_function_call(pop_emit_error);
    will_return(pop_emit_error,
                BUTTERFLYFISH_STACK_SR_ERROR_STACK_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stack_sr_pop(
                    (struct butterflyfish_stack_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STACK_SR_ERROR_STACK_IS_EMPTY);
}

static void check_push_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_sr_push(NULL, (void *) 1),
            BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL);
}

static void check_push_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_sr_push((void *) 1, NULL),
            BUTTERFLYFISH_STACK_SR_ERROR_VALUE_IS_NULL);
}

static int push_emit_error(void *const object,
                           struct triggerfish_strong *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    return mock();
}

static void check_push_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_stack_sr stack_sr = {
            .push = push_emit_error
    };
    struct object {
        const struct butterflyfish_stack_sr *stack_sr;
    };
    struct object instance = {
            .stack_sr = &stack_sr
    };
    expect_function_call(push_emit_error);
    will_return(push_emit_error,
                BUTTERFLYFISH_STACK_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_stack_sr_push(
                    (struct butterflyfish_stack_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STACK_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_push_error_on_value_is_invalid(void **state) {
    const struct butterflyfish_stack_sr stack_sr = {
            .push = push_emit_error
    };
    struct object {
        const struct butterflyfish_stack_sr *stack_sr;
    };
    struct object instance = {
            .stack_sr = &stack_sr
    };
    expect_function_call(push_emit_error);
    will_return(push_emit_error,
                BUTTERFLYFISH_STACK_SR_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_stack_sr_push(
                    (struct butterflyfish_stack_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STACK_SR_ERROR_VALUE_IS_INVALID);
}

static int
push_all_emit_error(void *const object,
                    const struct butterflyfish_stream_sr *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static void check_push_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_sr_push_all(NULL, (void *) 1),
            BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL);
}

static void check_push_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stack_sr_push_all((void *) 1, NULL),
            BUTTERFLYFISH_STACK_SR_ERROR_OTHER_IS_NULL);
}

static void check_push_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_stack_sr stack_sr = {
            .push_all = push_all_emit_error
    };
    struct object {
        const struct butterflyfish_stack_sr *stack_sr;
    };
    struct object instance = {
            .stack_sr = &stack_sr
    };
    expect_function_call(push_all_emit_error);
    will_return(push_all_emit_error,
                BUTTERFLYFISH_STACK_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_stack_sr_push_all(
                    (struct butterflyfish_stack_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STACK_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_as_stream_error_on_object_is_null),
            cmocka_unit_test(check_as_stream_error_on_out_is_null),
            cmocka_unit_test(check_as_stream),
            cmocka_unit_test(check_as_collection_error_on_object_is_null),
            cmocka_unit_test(check_as_collection_error_on_out_is_null),
            cmocka_unit_test(check_as_collection),
            cmocka_unit_test(check_as_reducible_stack_error_on_object_is_null),
            cmocka_unit_test(check_as_reducible_stack_error_on_out_is_null),
            cmocka_unit_test(check_as_reducible_stack),
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_count),
            cmocka_unit_test(check_as_reducible_stack_count),
            cmocka_unit_test(check_as_collection_count),
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
            cmocka_unit_test(check_push_error_on_value_is_invalid),
            cmocka_unit_test(check_push_all_error_on_object_is_null),
            cmocka_unit_test(check_push_all_error_on_other_is_null),
            cmocka_unit_test(check_push_all_error_on_memory_allocation_failed),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
