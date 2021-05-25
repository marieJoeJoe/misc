#lang racket
(define (fact x)
 (cond [(> x 0) (* x (fact (sub1 x)))]
[else 1]))
(fact 10)
;;(+ 7 8)
(string? "hello")
(rational? 1/2)
(equal? 42 "bar")
(expt 3 2)
(+ 1 2 3 4)
;;(tpye fact)
;;(fact "helloworld")
(boolean? #f)
(boolean? #t)

(string-length (string-append "Hello" ", " "World!"))
(print "• = compares numbers numerically:\n")
(= 1 1.0)    ;=> #t
(= 0.0 -0.0) ;=> #t
(= 1/10 0.1) ;=> #f
(print "• eq? compares objects by reference:\n")
;;• eq? compares objects by reference:
(eq? (cons 1 2) (cons 1 2))      ;=> #f
(let ([x (cons 1 2)]) (eq? x x)) ;=> #t


(define (transpos xss)(apply map list xss))
(transpos (list (list 1 2 3 4) (list 5 6 7 8) (list 9 10 11 12) (list 13 14 15 16)))
