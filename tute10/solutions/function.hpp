#ifndef AFDF4FA2_9B60_406E_BA4B_58048CE84E75
#define AFDF4FA2_9B60_406E_BA4B_58048CE84E75

#include <memory>
#include <utility>

template<typename T>
class Function;

template<typename ReturnType, typename... ArgTypes>
class Function<ReturnType(ArgTypes...)> {
public:
	Function() noexcept = delete;

	template<typename Functor>
	Function(Functor&& f)
	: m_wrapper(new FunctionModel<Functor>(std::forward<Functor>(f))) {}

	Function(Function&&) noexcept = delete;
	Function(const Function&) = delete;
	auto operator=(const Function& other) -> Function& = delete;
	auto operator=(Function&& other) noexcept -> Function& = delete;

	~Function() = default;

	auto operator()(ArgTypes... args) const -> ReturnType {
		return (*m_wrapper)(std::forward<ArgTypes>(args)...);
	}

	struct FunctionInterface {
		virtual auto operator()(ArgTypes... args) -> ReturnType = 0;
		virtual ~FunctionInterface() = default;
	};

	template<typename Functor>
	class FunctionModel final : public FunctionInterface {
	public:
		explicit FunctionModel(const Functor& functor)
		: m_func(functor) {}

		auto operator()(ArgTypes... args) -> ReturnType override {
			return m_func(std::forward<ArgTypes>(args)...);
		}

		virtual ~FunctionModel() = default;

	private:
		Functor m_func;
	};

private:
	std::unique_ptr<FunctionInterface> m_wrapper;
};

/* CTAD */
template<typename>
struct function_guide_helper {};

template<typename ReturnType, typename Scope, typename... ArgTypes>
struct function_guide_helper<ReturnType (Scope::*)(ArgTypes...)> {
	using type = ReturnType(ArgTypes...);
};

template<typename ReturnType, typename Scope, typename... ArgTypes>
struct function_guide_helper<ReturnType (Scope::*)(ArgTypes...) const> {
	using type = ReturnType(ArgTypes...);
};

template<typename ReturnType, typename Scope, typename... ArgTypes>
struct function_guide_helper<ReturnType (Scope::*)(ArgTypes...)&> {
	using type = ReturnType(ArgTypes...);
};

template<typename ReturnType, typename Scope, typename... ArgTypes>
struct function_guide_helper<ReturnType (Scope::*)(ArgTypes...) const&> {
	using type = ReturnType(ArgTypes...);
};

template<typename Op>
using function_guide_t = typename function_guide_helper<Op>::type;

template<typename ReturnType, typename... ArgTypes>
Function(ReturnType (*)(ArgTypes...)) -> Function<ReturnType(ArgTypes...)>;

template<typename Fn, typename Signature = function_guide_t<decltype(&Fn::operator())>>
Function(Fn) -> Function<Signature>;

#endif /* AFDF4FA2_9B60_406E_BA4B_58048CE84E75 */
