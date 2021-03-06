/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman
    Copyright (c) 2007 Dan Marsden
    Copyright (c) 2009-2010 Christopher Schmidt

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    This is an auto-generated file. Do not edit!
==============================================================================*/
namespace pdalboost {} namespace boost = pdalboost; namespace pdalboost { namespace fusion
{
    namespace detail
    {
        template<typename State, typename It, typename F>
        struct fold_lvalue_state
          : pdalboost::result_of<
                F(
                typename add_reference<typename add_const<State>::type>::type,
                typename fusion::result_of::deref<It>::type)
            >
        {};
        template<typename Result,int N>
        struct unrolled_fold
        {
            template<typename State, typename It0, typename F>
            static Result
            call(State const& state,It0 const& it0,F f)
            {
                typedef typename
                    result_of::next<
                        It0 const
                    >::type
                It1;
                It1 it1 = fusion::next(it0);
                typedef typename
                    result_of::next<
                        It1
                    >::type
                It2;
                It2 it2 = fusion::next(it1);
                typedef typename
                    result_of::next<
                        It2
                    >::type
                It3;
                It3 it3 = fusion::next(it2);
                typedef typename fold_lvalue_state<State,It0,F>::type State1;
                State1 const state1=f(state,fusion::deref(it0));
                typedef typename fold_lvalue_state<State1,It1,F>::type State2;
                State2 const state2=f(state1,fusion::deref(it1));
                typedef typename fold_lvalue_state<State2,It2,F>::type State3;
                State3 const state3=f(state2,fusion::deref(it2));
                return unrolled_fold<
                    Result
                  , N-4
                >::call(
                    f(state3,fusion::deref(it3)),
                    fusion::next(it3),
                    f);
            }
        };
        template<typename Result>
        struct unrolled_fold<Result,3>
        {
            template<typename State, typename It0, typename F>
            static Result
            call(State const& state,It0 const& it0,F f)
            {
                typedef typename
                    result_of::next<
                        It0 const
                    >::type
                It1;
                It1 it1 = fusion::next(it0);
                typedef typename
                    result_of::next<
                        It1
                    >::type
                It2;
                It2 it2 = fusion::next(it1);
                typedef typename fold_lvalue_state<State,It0,F>::type State1;
                State1 const state1=f(state,fusion::deref(it0));
                typedef typename fold_lvalue_state<State1,It1,F>::type State2;
                State2 const state2=f(state1,fusion::deref(it1));
                return f(state2,fusion::deref(it2));
            }
        };
        template<typename Result>
        struct unrolled_fold<Result,2>
        {
            template<typename State, typename It0, typename F>
            static Result
            call(State const& state,It0 const& it0,F f)
            {
                typedef typename fold_lvalue_state<State,It0,F>::type State1;
                State1 const state1=f(state,fusion::deref(it0));
                return f(
                    state1,
                    fusion::deref( fusion::next(it0)));
            }
        };
        template<typename Result>
        struct unrolled_fold<Result,1>
        {
            template<typename State, typename It0, typename F>
            static Result
            call(State const& state,It0 const& it0,F f)
            {
                return f(state,
                    fusion::deref(it0));
            }
        };
        template<typename Result>
        struct unrolled_fold<Result,0>
        {
            template<typename State, typename It0, typename F>
            static Result
            call(State const& state,It0 const&, F)
            {
                return static_cast<Result>(state);
            }
        };
        template<typename StateRef, typename It0, typename F, int N>
        struct result_of_unrolled_fold
        {
            typedef typename
                fold_lvalue_state<
                    StateRef
                  , It0 const
                  , F
                >::type
            rest1;
            typedef typename
                result_of::next<
                    It0 const
                >::type
            it1;
            typedef typename
                fold_lvalue_state<
                    rest1
                  , it1
                  , F
                >::type
            rest2;
            typedef typename
                result_of::next<it1>::type
            it2;
            typedef typename
                fold_lvalue_state<
                    rest2
                  , it2
                  , F
                >::type
            rest3;
            typedef typename
                result_of::next<it2>::type
            it3;
            typedef typename
                result_of_unrolled_fold<
                    typename fold_lvalue_state<
                        rest3
                      , it3
                      , F
                    >::type
                  , typename result_of::next<
                        it3
                    >::type
                  , F
                  , N-4
                >::type
            type;
        };
        template<typename StateRef, typename It0, typename F>
        struct result_of_unrolled_fold<
            StateRef
          , It0
          , F
          , 3
        >
        {
            typedef typename
                fold_lvalue_state<
                    StateRef
                  , It0 const
                  , F
                >::type
            rest1;
            typedef typename
                result_of::next<
                    It0 const
                >::type
            it1;
            typedef typename
                fold_lvalue_state<
                    typename fold_lvalue_state<
                        rest1
                      , it1
                      , F
                    >::type
                  , typename result_of::next<
                        it1 const
                    >::type const
                  , F
                >::type
            type;
        };
        template<typename StateRef, typename It0, typename F>
        struct result_of_unrolled_fold<
            StateRef
          , It0
          , F
          , 2
        >
          : fold_lvalue_state<
                typename fold_lvalue_state<
                    StateRef
                  , It0 const
                  , F
                >::type
              , typename result_of::next<
                    It0 const
                >::type const
              , F
            >
        {};
        template<typename StateRef, typename It0, typename F>
        struct result_of_unrolled_fold<
            StateRef
          , It0
          , F
          , 1
        >
          : fold_lvalue_state<
                StateRef
              , It0 const
              , F
            >
        {};
        template<typename StateRef, typename It0, typename F>
        struct result_of_unrolled_fold<
            StateRef
          , It0
          , F
          , 0
        >
        {
            typedef StateRef type;
        };
        template<typename StateRef, typename It0, typename F, int SeqSize>
        struct result_of_first_unrolledfold
        {
            typedef typename
                result_of_unrolled_fold<
                    typename pdalboost::result_of<
                        F(
                            StateRef,
                            typename fusion::result_of::deref< It0 const>::type
                        )
                    >::type
                  , typename result_of::next<
                        It0 const
                    >::type
                  , F
                  , SeqSize-1
                >::type
            type;
        };
        template<int SeqSize, typename StateRef, typename Seq, typename F>
        struct fold_impl
        {
            typedef typename
                result_of_first_unrolledfold<
                    StateRef
                  , typename result_of::begin<Seq>::type
                  , F
                  , SeqSize
                >::type
            type;
            static type
            call(StateRef state, Seq& seq, F f)
            {
                typedef
                    unrolled_fold<
                        type
                      , SeqSize
                    >
                unrolled_impl;
                return unrolled_impl::call(
                    state,
                    fusion::begin(seq),
                    f);
            }
        };
        template<typename StateRef, typename Seq, typename F>
        struct fold_impl<0,StateRef,Seq,F>
        {
            typedef StateRef type;
            static StateRef
            call(StateRef state, Seq&, F)
            {
                return static_cast<StateRef>(state);
            }
        };
        template<typename Seq, typename State, typename F, bool IsSegmented>
        struct result_of_fold
          : fold_impl<
                result_of::size<Seq>::value
              , typename add_reference<
                    typename add_const<State>::type
                >::type
              , Seq
              , F
            >
        {};
    }
    namespace result_of
    {
        template<typename Seq, typename State, typename F>
        struct fold
          : detail::result_of_fold<
                Seq
              , State
              , F
              , traits::is_segmented<Seq>::type::value
            >
        {};
    }
    template<typename Seq, typename State, typename F>
    inline typename result_of::fold<
        Seq
      , State const
      , F
    >::type
    fold(Seq& seq, State const& state, F f)
    {
        return result_of::fold<Seq,State const,F>::call(
            state,
            seq,
            f);
    }
    template<typename Seq, typename State, typename F>
    inline typename result_of::fold<
        Seq const
      , State const
      , F
    >::type
    fold(Seq const& seq, State const& state, F f)
    {
        return result_of::fold<Seq const,State const,F>::call(
            state,
            seq,
            f);
    }
    template<typename Seq, typename State, typename F>
    inline typename result_of::fold<
        Seq
      , State const
      , F
    >::type
    fold(Seq& seq, State& state, F f)
    {
        return result_of::fold<Seq,State,F>::call(
            state,
            seq,
            f);
    }
    template<typename Seq, typename State, typename F>
    inline typename result_of::fold<
        Seq const
      , State const
      , F
    >::type
    fold(Seq const& seq, State& state, F f)
    {
        return result_of::fold<Seq const,State,F>::call(
            state,
            seq,
            f);
    }
}}
