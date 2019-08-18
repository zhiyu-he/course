#-*- coding: utf-8 -*-


import tensorflow as tf

if __name__ == '__main__':

    # 一阶的Tensor
    W = tf.Variable(initial_value=tf.random_normal(shape=(1,4), mean=100, stddev=0.35), name='W')
    b = tf.Variable(tf.zeros([4]), name='b')


    sess = tf.Session()
    sess.run(tf.global_variables_initializer())
    sess.run([W, b])

    sess.run(tf.assign_add(b, [1,1,1,1]))
    
    check = sess.run(b)
    print(check)
    
    '''
    # saver example
    v1 = tf.Variable(..., name='v1')
    v2 = tf.Variable(..., name='v2')
    saver = tf.train.Saver({'v1': v1, 'v2': v2})
    saver = tf.train.Saver([v1,v2])
    saver = tf.train.Saver({v.op.name: v for v in [v1, v2]})
    tf.train.saver.save(sess, 'my-model', global_step=0)    # --> filename: 'my-model-0'
    '''
    
    saver = tf.train.Saver({'W': W, 'b': b})
    # file=index+data+meta
    saver.save(sess, './summary/test.ckpt', global_step=0)  # global_step 恢复到指定step的参数信息
    sess.run(tf.assign_add(b, [1,1,1,1]))
    check = sess.run(b)
    print(check)

    saver.restore(sess, './summary/test.ckpt-0')  
    check = sess.run(b)
    print(check)

