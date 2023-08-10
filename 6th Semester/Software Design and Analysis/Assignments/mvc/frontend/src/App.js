import './App.css';
import { BrowserRouter as Router, Routes, Route } from "react-router-dom";
import Component from './Component';
import Profile from './Profile';

function App() {
  return (
    <div style={{ margin: '50px' }}>
      <Router>
        <Routes>
          <Route path="/" element={<Component />} />
          <Route path="/profile" element={<Profile/>} />
        </Routes>
      </Router>
    </div>
  );
}

export default App;
