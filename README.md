## HelloWorldC [![Build Status](https://travis-ci.org/MichaelStedman/HelloWorldC.svg?branch=master)](https://travis-ci.org/MichaelStedman/HelloWorldC) [![Coverage Status](https://coveralls.io/repos/github/MichaelStedman/HelloWorldC/badge.svg?branch=master)](https://coveralls.io/github/MichaelStedman/HelloWorldC?branch=master)
This is just a little project for me to learn some C, Git and GitHub.

#### Why learn C at the age of 60?
I've played with Clojure, Rust, Go and Python over the past year. I've also written C# on Linux Mint. None of them were particularly satisfactory experiences. Be it REPL, compile times, unit testing or debugging. None of them are as smooth as developing C# in Visual Studio running on Windows. I thought I'd go "back to basics" and give C a whirl.

#### Why use MinUnit?
It was only three lines of macro to get started. Then I stumbled across an enhanced version of MinUnit by David Siñuela Pastor. At the moment it does everything I need.

#### Why write a bunch of string handling functions?
1. The standard string functions in C are so dangerous! No wonder there are so many exploits.
2. Didn't have any betters ideas about what to write.

#### Why use Travis CI for a Hello World project?
I hadn't used Travis (or any CI) before and these tools are generally easier to use with simple projects.

#### Why is Coveralls showing "coverage unknown"?
I've only just added Coveralls and the set up is confusing. I followed the instructions then suddenly it tells me to add something to my gemfile. What gemfile? AFAIK gemfiles are related to Ruby. Further work/investigation required.
