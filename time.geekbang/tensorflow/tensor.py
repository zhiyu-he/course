# -*- coding: utf-8 -*-

import tensorflow as tf


def print_args(*args):
    for arg in args:
        print(arg)

if __name__ == '__main__':
    mammal = tf.Variable("Elephant", tf.string)
    igniticn = tf.Variable(451, tf.int16)
    floating = tf.Variable(3.14159265359, tf.float64)
    its_complicated = tf.Variable(12.3 - 4.85j, tf.complex64)

    print_args(mammal, igniticn, floating, its_complicated)

    mystr = tf.Variable(["Hello", "World"], tf.string)
    cool_numbers = tf.Variable([3.14159, 2.71828], tf.float32)
    first_primes = tf.Variable([2, 3, 5, 7, 11], tf.int32)
    its_very_complicated = tf.Variable([12.3 - 4.85j, 7.5 - 6.23j], tf.complex64)

    print_args(mystr, cool_numbers, first_primes, its_very_complicated)

    mymat = tf.Variable([[7], [11]], tf.int16)
    myxor = tf.Variable([[False, True], [True, False]], tf.bool)
    linear_squares = tf.Variable([[4], [9], [16], [25]], tf.int32)
    squarish_squares = tf.Variable([[4, 9], [16, 25]], tf.int32)
    rank_of_squares = tf.rank(squarish_squares)
    mymatC = tf.Variable([[7], [11]], tf.int32)

    print_args(mymat, myxor, linear_squares, squarish_squares, rank_of_squares, mymatC)
    
    my_image = tf.zeros([10, 299, 299, 3])

    print(my_image)
