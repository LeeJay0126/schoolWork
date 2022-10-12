import { Route } from "react-router-dom";

import Home from "./components/Home";
import Error from "./components/Error";
import About from "./components/About";
import Navbar from "./components/Navbar";

function App() {

  return (
    <div>
      <Navbar />
    <div className="todoapp stack-large">
      <Switch>
        <Route path="/" component={Home} exact />
        <Route path="/about" component={About} />
        <Route component={Error} />
      </Switch>
    </div>
      </div>
  );
}

export default App;
