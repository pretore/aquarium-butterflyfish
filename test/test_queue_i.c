#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

static void check_as_stream_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_i_as_stream(NULL, (void *) 1),
            BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_stream_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_i_as_stream((void *) 1, NULL),
            BUTTERFLYFISH_QUEUE_I_ERROR_OUT_IS_NULL);
}

static void check_as_stream(void **state) {
    struct butterflyfish_queue_i queue = {};
    const struct butterflyfish_stream_i *stream;
    assert_int_equal(butterflyfish_queue_i_as_stream(&queue, &stream), 0);
    assert_ptr_equal(&queue, stream);
}

static void check_as_collection_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_i_as_collection(NULL, (void *) 1),
            BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_collection_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_i_as_collection((void *) 1, NULL),
            BUTTERFLYFISH_QUEUE_I_ERROR_OUT_IS_NULL);
}

static void check_as_collection(void **state) {
    struct butterflyfish_queue_i queue = {};
    const struct butterflyfish_collection_i *collection;
    assert_int_equal(butterflyfish_queue_i_as_collection(
            &queue, &collection), 0);
    assert_ptr_equal(&queue, collection);
}

static void check_as_reducible_queue_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_i_as_reducible_queue(NULL, (void *) 1),
            BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_reducible_queue_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_i_as_reducible_queue((void *) 1, NULL),
            BUTTERFLYFISH_QUEUE_I_ERROR_OUT_IS_NULL);
}

static void check_as_reducible_queue(void **state) {
    struct butterflyfish_queue_i queue = {};
    struct butterflyfish_reducible_queue_i *reducible_queue;
    assert_int_equal(butterflyfish_queue_i_as_reducible_queue(
            &queue, &reducible_queue), 0);
    assert_ptr_equal(&queue, reducible_queue);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_i_count(NULL, (void *) 1),
            BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_i_count((void *) 1, NULL),
            BUTTERFLYFISH_QUEUE_I_ERROR_OUT_IS_NULL);
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
    const struct butterflyfish_queue_i queue_i = {
            .reducible_queue_i.collection_i.count = count
    };
    struct object {
        const struct butterflyfish_queue_i *queue_i;
    };
    struct object instance = {
            .queue_i = &queue_i
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_queue_i_count(
                    (const struct butterflyfish_queue_i *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static void check_as_reducible_queue_count(void **state) {
    srand(time(NULL));
    const struct butterflyfish_queue_i queue_i = {
            .reducible_queue_i.collection_i.count = count
    };
    struct object {
        const struct butterflyfish_queue_i *queue_i;
    };
    struct object instance = {
            .queue_i = &queue_i
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_reducible_queue_i_count(
                    (const struct butterflyfish_reducible_queue_i *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static void check_as_collection_count(void **state) {
    srand(time(NULL));
    const struct butterflyfish_queue_i queue_i = {
            .reducible_queue_i.collection_i.count = count
    };
    struct object {
        const struct butterflyfish_queue_i *queue_i;
    };
    struct object instance = {
            .queue_i = &queue_i
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_collection_i_count(
                    (const struct butterflyfish_collection_i *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static int fl_emit_error(const void *const object,
                         const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_first_error_on_queue_is_empty(void **state) {
    const struct butterflyfish_queue_i queue_i = {
            .reducible_queue_i.collection_i.stream_i.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_queue_i *queue_i;
    };
    struct object instance = {
            .queue_i = &queue_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_QUEUE_I_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_queue_i_first(
                    (const struct butterflyfish_queue_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_QUEUE_I_ERROR_QUEUE_IS_EMPTY);
}

static void
check_as_reducible_queue_first_error_on_queue_is_empty(void **state) {
    const struct butterflyfish_queue_i queue_i = {
            .reducible_queue_i.collection_i.stream_i.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_queue_i *queue_i;
    };
    struct object instance = {
            .queue_i = &queue_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_QUEUE_I_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_reducible_queue_i_first(
                    (const struct butterflyfish_reducible_queue_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_I_ERROR_QUEUE_IS_EMPTY);
}

static void
check_as_collection_first_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_queue_i queue_i = {
            .reducible_queue_i.collection_i.stream_i.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_queue_i *queue_i;
    };
    struct object instance = {
            .queue_i = &queue_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_QUEUE_I_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_i_first(
                    (const struct butterflyfish_collection_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_ERROR_COLLECTION_IS_EMPTY);
}

static void check_as_stream_first_error_on_stream_is_empty(void **state) {
    const struct butterflyfish_queue_i queue_i = {
            .reducible_queue_i.collection_i.stream_i.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_queue_i *queue_i;
    };
    struct object instance = {
            .queue_i = &queue_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_QUEUE_I_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stream_i_first(
                    (const struct butterflyfish_stream_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_I_ERROR_STREAM_IS_EMPTY);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_i_first(NULL, (void *) 1),
            BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_i_first((void *) 1, NULL),
            BUTTERFLYFISH_QUEUE_I_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_i_last(NULL, (void *) 1),
            BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_i_last((void *) 1, NULL),
            BUTTERFLYFISH_QUEUE_I_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_queue_is_empty(void **state) {
    const struct butterflyfish_queue_i queue_i = {
            .reducible_queue_i.collection_i.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_queue_i *queue_i;
    };
    struct object instance = {
            .queue_i = &queue_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_QUEUE_I_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_queue_i_last(
                    (const struct butterflyfish_queue_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_QUEUE_I_ERROR_QUEUE_IS_EMPTY);
}

static void
check_as_reducible_queue_last_error_on_queue_is_empty(void **state) {
    const struct butterflyfish_queue_i queue_i = {
            .reducible_queue_i.collection_i.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_queue_i *queue_i;
    };
    struct object instance = {
            .queue_i = &queue_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_QUEUE_I_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_reducible_queue_i_last(
                    (const struct butterflyfish_reducible_queue_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_I_ERROR_QUEUE_IS_EMPTY);
}

static void
check_as_collection_last_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_collection_i collection_i = {
            .last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_collection_i *collection_i;
    };
    struct object instance = {
            .collection_i = &collection_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_QUEUE_I_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_i_last(
                    (const struct butterflyfish_collection_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_ERROR_COLLECTION_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_i_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_i_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_QUEUE_I_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_i_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_QUEUE_I_ERROR_OUT_IS_NULL);
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
    const struct butterflyfish_queue_i queue_i = {
            .reducible_queue_i.collection_i.stream_i.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_queue_i *queue_i;
    };
    struct object instance = {
            .queue_i = &queue_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_QUEUE_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_queue_i_next(
                    (const struct butterflyfish_queue_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_QUEUE_I_ERROR_END_OF_SEQUENCE);
}

static void
check_as_reducible_queue_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_queue_i queue_i = {
            .reducible_queue_i.collection_i.stream_i.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_queue_i *queue_i;
    };
    struct object instance = {
            .queue_i = &queue_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_QUEUE_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_reducible_queue_i_next(
                    (const struct butterflyfish_reducible_queue_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_I_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_queue_i queue_i = {
            .reducible_queue_i.collection_i.stream_i.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_queue_i *queue_i;
    };
    struct object instance = {
            .queue_i = &queue_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_QUEUE_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_i_next(
                    (const struct butterflyfish_collection_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_ERROR_END_OF_SEQUENCE);
}

static void check_as_stream_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_queue_i queue_i = {
            .reducible_queue_i.collection_i.stream_i.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_queue_i *queue_i;
    };
    struct object instance = {
            .queue_i = &queue_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_QUEUE_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stream_i_next(
                    (const struct butterflyfish_stream_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_I_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_i_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_i_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_QUEUE_I_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_i_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_QUEUE_I_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_queue_i queue_i = {
            .reducible_queue_i.collection_i.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_queue_i *queue_i;
    };
    struct object instance = {
            .queue_i = &queue_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_QUEUE_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_queue_i_prev(
                    (const struct butterflyfish_queue_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_QUEUE_I_ERROR_END_OF_SEQUENCE);
}

static void
check_as_reducible_queue_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_queue_i queue_i = {
            .reducible_queue_i.collection_i.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_queue_i *queue_i;
    };
    struct object instance = {
            .queue_i = &queue_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_QUEUE_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_reducible_queue_i_prev(
                    (const struct butterflyfish_reducible_queue_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_I_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_queue_i queue_i = {
            .reducible_queue_i.collection_i.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_queue_i *queue_i;
    };
    struct object instance = {
            .queue_i = &queue_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_QUEUE_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_i_prev(
                    (const struct butterflyfish_collection_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_ERROR_END_OF_SEQUENCE);
}

static void check_remove_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_i_remove(NULL, (void *) 1),
            BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_i_remove((void *) 1, NULL),
            BUTTERFLYFISH_QUEUE_I_ERROR_OUT_IS_NULL);
}

static int
remove_emit_error(void *const object,
                  struct sea_turtle_integer *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_remove_error_on_queue_is_empty(void **state) {
    const struct butterflyfish_queue_i queue_i = {
            .reducible_queue_i.remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_queue_i *queue_i;
    };
    struct object instance = {
            .queue_i = &queue_i
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_QUEUE_I_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_queue_i_remove(
                    (struct butterflyfish_queue_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_QUEUE_I_ERROR_QUEUE_IS_EMPTY);
}

static void
check_as_reducible_queue_remove_error_on_queue_is_empty(void **state) {
    const struct butterflyfish_queue_i queue_i = {
            .reducible_queue_i.remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_queue_i *queue_i;
    };
    struct object instance = {
            .queue_i = &queue_i
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_QUEUE_I_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_reducible_queue_i_remove(
                    (struct butterflyfish_reducible_queue_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_I_ERROR_QUEUE_IS_EMPTY);
}

static void check_add_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_i_add(NULL, (void *) 1),
            BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL);
}

static void check_add_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_i_add((void *) 1, NULL),
            BUTTERFLYFISH_QUEUE_I_ERROR_VALUE_IS_NULL);
}

static int add_emit_error(void *const object,
                          const struct sea_turtle_integer *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    return mock();
}

static void check_add_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_queue_i queue_i = {
            .add = add_emit_error
    };
    struct object {
        const struct butterflyfish_queue_i *queue_i;
    };
    struct object instance = {
            .queue_i = &queue_i
    };
    expect_function_call(add_emit_error);
    will_return(add_emit_error,
                BUTTERFLYFISH_QUEUE_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_queue_i_add(
                    (struct butterflyfish_queue_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_QUEUE_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_add_error_on_value_is_invalid(void **state) {
    const struct butterflyfish_queue_i queue_i = {
            .add = add_emit_error
    };
    struct object {
        const struct butterflyfish_queue_i *queue_i;
    };
    struct object instance = {
            .queue_i = &queue_i
    };
    expect_function_call(add_emit_error);
    will_return(add_emit_error,
                BUTTERFLYFISH_QUEUE_I_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_queue_i_add(
                    (struct butterflyfish_queue_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_QUEUE_I_ERROR_VALUE_IS_INVALID);
}

static int
add_all_emit_error(void *const object,
                   const struct butterflyfish_stream_i *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static void check_add_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_i_add_all(NULL, (void *) 1),
            BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL);
}

static void check_add_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_i_add_all((void *) 1, NULL),
            BUTTERFLYFISH_QUEUE_I_ERROR_OTHER_IS_NULL);
}

static void check_add_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_queue_i queue_i = {
            .add_all = add_all_emit_error
    };
    struct object {
        const struct butterflyfish_queue_i *queue_i;
    };
    struct object instance = {
            .queue_i = &queue_i
    };
    expect_function_call(add_all_emit_error);
    will_return(add_all_emit_error,
                BUTTERFLYFISH_QUEUE_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_queue_i_add_all(
                    (struct butterflyfish_queue_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_QUEUE_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_as_stream_error_on_object_is_null),
            cmocka_unit_test(check_as_stream_error_on_out_is_null),
            cmocka_unit_test(check_as_stream),
            cmocka_unit_test(check_as_collection_error_on_object_is_null),
            cmocka_unit_test(check_as_collection_error_on_out_is_null),
            cmocka_unit_test(check_as_collection),
            cmocka_unit_test(check_as_reducible_queue_error_on_object_is_null),
            cmocka_unit_test(check_as_reducible_queue_error_on_out_is_null),
            cmocka_unit_test(check_as_reducible_queue),
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_count),
            cmocka_unit_test(check_as_reducible_queue_count),
            cmocka_unit_test(check_as_collection_count),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_queue_is_empty),
            cmocka_unit_test(check_as_reducible_queue_first_error_on_queue_is_empty),
            cmocka_unit_test(check_as_collection_first_error_on_collection_is_empty),
            cmocka_unit_test(check_as_stream_first_error_on_stream_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_queue_is_empty),
            cmocka_unit_test(check_as_reducible_queue_last_error_on_queue_is_empty),
            cmocka_unit_test(check_as_collection_last_error_on_collection_is_empty),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_item_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_reducible_queue_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_collection_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_stream_next_error_on_end_of_sequence),
            cmocka_unit_test(check_prev_error_on_object_is_null),
            cmocka_unit_test(check_prev_error_on_item_is_null),
            cmocka_unit_test(check_prev_error_on_out_is_null),
            cmocka_unit_test(check_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_as_reducible_queue_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_as_collection_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_remove_error_on_object_is_null),
            cmocka_unit_test(check_remove_error_on_out_is_null),
            cmocka_unit_test(check_remove_error_on_queue_is_empty),
            cmocka_unit_test(check_as_reducible_queue_remove_error_on_queue_is_empty),
            cmocka_unit_test(check_add_error_on_object_is_null),
            cmocka_unit_test(check_add_error_on_value_is_null),
            cmocka_unit_test(check_add_error_on_memory_allocation_failed),
            cmocka_unit_test(check_add_error_on_value_is_invalid),
            cmocka_unit_test(check_add_all_error_on_object_is_null),
            cmocka_unit_test(check_add_all_error_on_other_is_null),
            cmocka_unit_test(check_add_all_error_on_memory_allocation_failed),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
