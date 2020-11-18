TF Test Sort [![License][license-img]][license-url]
=
Simple Travis example for C using GCC compiler based on the identifier program presented by Delamaro et al. "Introdução ao Teste de Software". Elsevier. 2007.

Test results:

[<img alt="Build Status" src="https://travis-ci.org/tgambim/tf-test-sort.svg?branch=main" height="40">][travis-url]

Important files:

* [identifier.c](identifier.c)
* [Makefile](Makefile)
* [.travis.yml](.travis.yml)

License
-------
MIT License. See [LICENSE](LICENSE) for details.

[main-url]: https://github.com/tgambim/tf-test-sort
[readme-url]: https://github.com/tgambim/tf-test-sort/blob/main/README.md
[license-url]: https://github.com/tgambim/tf-test-sort/blob/main/LICENSE
[license-img]: https://img.shields.io/github/license/rsp/travis-hello-modern-cpp.svg
[travis-url]: https://travis-ci.org/tgambim/tf-test-sort
[travis-img]: https://travis-ci.org/tgambim/tf-test-sort.svg?branch=master
[github-follow-url]: https://github.com/tgambim


# How to Use
  
  Dentro do directory root execute o make
  
 * make app                         ->  Builda os sources
 * make test                        ->  Teste do Unity
 * make cov                         ->  Para usar o gcov sobre o arquivo sort.c
 * make cppcheck                    ->  Para usar o cppcheck sobre array.c , get_opt.c , sort.c e main.c
 * make valgrind method=[method]    ->  Para usar o valgrind para um metodo especifico [quick, heap, selection, shell, merge]. Os parametros sao fixos em <-n 6 -s descending -P>. 
 * make sanitizer method=[method]   ->  Para usar o sanitizer para um metodo especifico [quick, heap, selection, shell, merge]. Os parametros sao fixos em <-n 6 -s descending -P>.
 * make clean                       ->  Limpa todos arquivos gerados durante alguma das execucoes.
