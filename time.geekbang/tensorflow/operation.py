# -*- coding: utf-8 -*-


import tensorflow as tf

if __name__ == '__main__':
    a = tf.constant(2)
    b = tf.constant(3)
    with tf.Session() as sess:
        print("a: %i" % sess.run(a))
        print("b: %i" % sess.run(b))
        print("Addition with constants: %i" % sess.run(a+b))
        print("Multiplication with constants: %i" % sess.run(a*b))
    
    # placeholder
    x = tf.placeholder(tf.int16, shape=(), name='x')
    y = tf.placeholder(tf.int16, shape=(), name='y')

    add = tf.add(x, y)
    mul = tf.multiply(x, y)
    with tf.Session() as sess:
        print("Addition with variables: %i" % sess.run(add, feed_dict={x:2, y:3}))
        print("Multiplication with variables: %i" % sess.run(mul, feed_dict={x:2, y:3}))
    

